# rails.py
from nemoguardrails.actions import action

@action(name="analyze_brand_risk")
async def analyze_brand_risk(user_input: str) -> str:
    """
    Analyzes the input question for potential brand risk.
    Returns 'damaging' or 'safe'.
    """
    user_input = user_input.lower()
    risky_keywords = [
        "politics", "religion", "war", "crime", "violence", "racism", "discrimination",
        "fake", "hoax", "conspiracy", "lie",
        "sucks", "hate", "worst", "scam", "fraud", "illegal", "corrupt", "abuse",
        "child labor", "unsafe", "toxic", "banned", "lawsuit",
        "death", "drugs", "sex", "gambling"
    ]
    for keyword in risky_keywords:
        if keyword in user_input:
            return "damaging"
    return "safe"