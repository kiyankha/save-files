email = input("Enter your email:").strip()

username = email[:email.index('@')]
domain = email[email.index('@') +1:]

print(f"your username is {username} and your domain is {domain}")
