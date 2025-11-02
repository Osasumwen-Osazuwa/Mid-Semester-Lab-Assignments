# Import the datetime module
import datetime

# Ask the user for their name
name = input("Hello! What is your name?\n> ")

# Respond with a personalized greeting
print(f"\nNice to meet you, {name}!")

# Get the current date
today = datetime.date.today()

# Format and display the date in a readable way
formatted_date = today.strftime("%B %d, %Y")
print(f"Today’s date is {formatted_date}.")
