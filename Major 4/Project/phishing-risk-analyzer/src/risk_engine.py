def calculate_risk(features):

    score = 0
    reasons = []

    # Rule 1: IP address
    if features["is_ip"]:
        score += 20
        reasons.append(
            "IP address is used instead of a domain name."
        )

    # Rule 2: HTTP instead of HTTPS
    if not features["https"]:
        score += 10
        reasons.append(
            "HTTPS is not being used."
        )

    # Rule 3: Suspicious keywords
    keywords = features["suspicious_keywords"]

    if len(keywords) > 0:
        keyword_score = min(len(keywords) * 5, 25)
        score += keyword_score

        reasons.append(
            "Suspicious keywords detected: "
            + ", ".join(keywords)
        )

    # Rule 4: @ symbol
    if features["has_at_symbol"]:
        score += 15
        reasons.append(
            "@ symbol detected in the URL."
        )

    # Rule 5: Long URL
    if features["url_length"] > 75:
        score += 10
        reasons.append(
            "URL is unusually long."
        )

    # Rule 6: Multiple subdomains
    if features["subdomain_count"] >= 3:
        score += 10
        reasons.append(
            "Multiple subdomains detected."
        )

    # Rule 7: Multiple hyphens
    if features["hyphen_count"] >= 3:
        score += 5
        reasons.append(
            "Multiple hyphens detected in the URL."
        )

    # Rule 8: Deep URL path
    if features["url_depth"] >= 4:
        score += 5
        reasons.append(
            "URL contains a deep path structure."
        )

    # Maximum score = 100
    score = min(score, 100)

    # Determine risk level
    if score <= 30:
        risk_level = "LOW"

    elif score <= 60:
        risk_level = "MEDIUM"

    elif score <= 80:
        risk_level = "HIGH"

    else:
        risk_level = "CRITICAL"

    return score, risk_level, reasons