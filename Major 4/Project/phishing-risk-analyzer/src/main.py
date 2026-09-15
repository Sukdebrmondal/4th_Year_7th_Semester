from validator import normalize_url, validate_url
from feature_extractor import extract_features
from risk_engine import calculate_risk
from report_generator import generate_report


print("===================================")
print("     Phishing Risk Analyzer")
print("===================================")

url = input("Enter a URL: ")


# Step 1: Normalize URL
url = normalize_url(url)


# Step 2: Validate URL
is_valid, message = validate_url(url)


if not is_valid:

    print()
    print("ERROR:", message)
    print("Please enter a valid HTTP/HTTPS URL.")

    raise SystemExit(1)


# Step 3: Extract features
features = extract_features(url)


# Step 4: Calculate risk
score, risk_level, rules = calculate_risk(features)


# Step 5: Generate final report
generate_report(
    url,
    features,
    score,
    risk_level,
    rules
)