from pyscript import document

clan = {
    "name": "Gladiators",
    "members":[]
}

def display_members():
    output = " "

    for member in clan["members"]:
        output += f"{member['name']}<br>"

    document.querySelector("")
users = [
    {"name": "Matthew", "goal": 150, "eaten": 150},
    {"name": "Alex", "goal": 160, "eaten": 120},
    {"name": "LeBron", "goal": 200, "eaten": 120},
    ]

winners = []
losers = []
for user in users:
    user["remaining"] = user["goal"] - user["eaten"]
    
sorted_users = sorted(users, key=lambda x: x["remaining"])

print ("\nLeaderboard:")
for i, user in enumerate(sorted_users, start =1):
    print(f"Placement:{i} {user['name']} - {user['remaining']}g left")

    if (user["remaining"] <= 0):
        winners.append(user)
    else:
        losers.append(user)

print ("\nWinners:")
for user in winners:
    print(f"{user['name']} wins")

print ("\nLosers:")
for user in losers:
    print(f"{user['name']} must do a forfeit")
print ("\n")
