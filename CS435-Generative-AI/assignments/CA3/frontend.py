import streamlit as st
import requests
import subprocess 

API_URL = "http://127.0.0.1:8000/check_brand_risk"

st.title("Brand Risk Checker")
st.write("Enter a question or statement to check if it’s safe for a brand.")

question = st.text_input("Your Question:", "")

if st.button("Check Brand Risk"):
    if question:
        payload = {"question": question}

        curl_cmd = f'curl -X POST "{API_URL}" -H "Content-Type: application/json" -d \'{{"question": "{question}"}}\''
        try:
            result = subprocess.check_output(curl_cmd, shell=True, text=True)
            result = eval(result)["result"]  # Unsafe eval, use json.loads in production
            if result == "damaging":
                st.error("Potentially damaging to brand")
            elif result == "safe":
                st.success("Safe for the brand")
        except subprocess.CalledProcessError as e:
            st.error(f"Error with curl: {str(e)}")

    else:
        st.warning("Please enter a question!")

st.write("FastAPI for the app, and Gemini for the model.")