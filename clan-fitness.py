users = [
    {"name": "Matthew", "goal": 150, "eaten": 150},
    {"name": "Alex", "goal": 160, "eaten": 120},
    {"name": "LeBron", "goal": 200, "eaten": 120},
    ]


for user in users:
    remaining = user["goal"] - user["eaten"]

    print(f"\nUser: {user['name']}")
    print (f"Protein remaining: {remaining}g")

    if remaining > 0:
        print(f"What the hell are you doing, {user['name']}?")
    else:
        print("AYEEEE LETS GOOOOO")
