import math
import random

lower_num = int(input("enter your first number:"))
upper_num = int(input("enter your second number:"))

y = round(math.log(upper_num - lower_num + 1, 2))

if lower_num >= upper_num:
    raise ValueError("first number must be less than second number")

print("\n\tyou've only", y, "chances to try\n")

count = 0

ai_num = random.randint(lower_num, upper_num)
print("starting the game")


while count < y:
    count += 1

    guessed_number = int(input("guess a number :"))

    if guessed_number == ai_num:
        print("You won!!!")
        break
    elif guessed_number > ai_num:
        print("You guessed high")
    elif guessed_number < ai_num:
        print("You guessed small")

if count > y:
    print(f"The number was {ai_num}\n\tGoodbye")
