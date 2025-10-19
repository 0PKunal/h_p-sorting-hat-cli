# The Sorting Hat

def ask_question(question, options, scores):
    # Ask a question and update house scores based on the answer.
    print("\n" + question)
    for i, option in enumerate(options, 1):
        print(f"    {i}) {option}")
    
    while True:
        try:
            answer = int(input("Enter your answer: "))
            if 1 <= answer <= len(options):
                for house, points in scores[answer - 1].items():
                    house_scores[house] += points
                break
            else:
                print("Invalid input. Please enter a number corresponding to the options.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")

    print("-" * 20)  # Separator


# Initialize scores for each house
house_scores = {
    "Gryffindor": 0,
    "Ravenclaw": 0,
    "Hufflepuff": 0,
    "Slytherin": 0
}

# Questions and scoring logic
questions = [
    {
        "question": "Q1) Do you like Dawn or Dusk?",
        "options": ["Dawn", "Dusk"],
        "scores": [
            {"Gryffindor": 1, "Ravenclaw": 1},
            {"Hufflepuff": 1, "Slytherin": 1}
        ]
    },
    {
        "question": "Q2) When I’m dead, I want people to remember me as:",
        "options": ["The Good", "The Great", "The Wise", "The Bold"],
        "scores": [
            {"Hufflepuff": 2},
            {"Slytherin": 2},
            {"Ravenclaw": 2},
            {"Gryffindor": 2}
        ]
    },
    {
        "question": "Q3) Which kind of instrument most pleases your ear?",
        "options": ["The violin", "The trumpet", "The piano", "The drum"],
        "scores": [
            {"Slytherin": 4},
            {"Hufflepuff": 4},
            {"Ravenclaw": 4},
            {"Gryffindor": 4}
        ]
    }
]

# Ask each question
for q in questions:
    ask_question(q["question"], q["options"], q["scores"])

# Determine the house with the highest score
sorted_houses = sorted(house_scores.items(), key=lambda x: x[1], reverse=True)
top_house = sorted_houses[0]

# Print the results
print("House Scores:")
for house, score in house_scores.items():
    print(f"{house}: {score}")

print("\nCongratulations! You belong to:", top_house[0], "\n")