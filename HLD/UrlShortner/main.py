from shortner import Shortner




obj = Shortner()
while True:
	print("\n--- URL Shortener Menu ---")
	print("1. Get tiny URL from long URL")
	print("2. Get Long Url from Tiny Url")
	choice = int(input("Enter your choice (1-3): "))
	if choice == 1:
		url = input('Enter Long Url ')
		print(obj.generate_tiny_url(url))
	elif choice == 2:
		url = input('Enter Short Url ')
		print(obj.get_original_url(url))
	else:
		break


