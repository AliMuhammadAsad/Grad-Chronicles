import os
from fastapi import FastAPI, HTTPException
import google.generativeai as genai
from pydantic import BaseModel

GEMINI_API_KEY = "<Enter your key here>"

genai.configure(api_key=GEMINI_API_KEY)
model = genai.GenerativeModel("gemini-1.5-flash")

app = FastAPI()

# Define request body model
class QuestionRequest(BaseModel):
    question: str

def check_brand_risk(question: str) -> str:
    try:
        prompt = (
            f"Analyze the following question or statement for potential brand risk. "
            f"Consider controversial topics, misinformation, defamation, offensive content, "
            f"or regulatory non-compliance. Respond with 'flag' if it's potentially damaging, "
            f"or 'safe' if it's not.\n\nQuestion: {question}"
        )
        response = model.generate_content(prompt)
        result = response.text.strip().lower()
        return "damaging" if "flag" in result else "safe"
    except Exception as e:
        raise HTTPException(status_code=500, detail=f"API Error: {str(e)}")

@app.post("/check_brand_risk")
async def check_brand_risk_endpoint(request: QuestionRequest):
    result = check_brand_risk(request.question)
    return {"result": result}