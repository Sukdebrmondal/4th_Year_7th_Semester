from url_parser import normalize_url, validate_url
from feature_extractor import extract_features
from risk_engine import calculate_risk


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
score, risk_level, reasons = calculate_risk(features)


print()
print("========== URL FEATURES ==========")

print("URL Length          :", features["url_length"])
print("HTTPS               :", features["https"])
print("IP Address          :", features["is_ip"])
print("Number of Dots      :", features["dot_count"])
print("Number of Hyphens   :", features["hyphen_count"])
print("@ Symbol Present    :", features["has_at_symbol"])
print("Subdomains          :", features["subdomain_count"])
print("Suspicious Keywords :", features["suspicious_keywords"])
print("URL Depth           :", features["url_depth"])
print("Special Characters  :", features["special_char_count"])


print()
print("========== RISK ANALYSIS ==========")

print("Risk Score           :", score, "/ 100")
print("Risk Level           :", risk_level)


print()
print("========== REASONS ================")

if len(reasons) == 0:
    print("No major suspicious characteristics detected.")

else:
    for reason in reasons:
        print("[!] " + reason)