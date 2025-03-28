# main.py
from nemoguardrails import LLMRails, RailsConfig
import asyncio

# Load the guardrails configuration from the current directory
config = RailsConfig.from_path("./")
rails = LLMRails(config)

def check_brand_risk(question: str) -> str:
    """
    Analyzes a question for potential brand risk using NeMo Guardrails.
    Returns 'Potentially damaging to brand' or 'Safe for the brand'.
    """
    # Run the guardrails flow synchronously
    result = asyncio.run(rails.generate_async(messages=[{"role": "user", "content": question}]))
    return result["content"]

# Test cases
if __name__ == "__main__":
    test_questions = [
        "Is your product made with child labor?",
        "What’s the weather like today?",
        "Your company supports hate groups, right?",
        "How do I use your app?"
    ]
    
    for question in test_questions:
        result = check_brand_risk(question)
        print(f"Question: '{question}' -> {result}")