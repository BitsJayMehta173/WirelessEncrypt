# Function to read and parse the keytable file
def parse_keytable(file_path):
    # Create an empty dictionary
    keytable = {}

    # Open the file and process each line
    with open(file_path, 'r') as file:
        for line in file:
            # Strip any extra whitespace and split the line
            line = line.strip()
            if line:  # Check if the line is not empty
                key, value = line.split(' : ')
                keytable[key] = value

    return keytable

# Function to get the code corresponding to a letter from the keytable
def get_code_from_keytable(keytable, character):
    return keytable.get(character.upper(), "Code not found")

# Main program
def main():
    # Path to your keytable.txt file
    file_path = 'keytable.txt'

    # Parse the keytable and store it in a dictionary
    keytable = parse_keytable(file_path)

    while True:
        user_input = input("Enter a letter (or 'exit' to quit): ")
        if user_input.lower() == 'exit':
            print("Exiting program.")
            break
        elif len(user_input) == 1 and user_input.isalpha():
            code = get_code_from_keytable(keytable, user_input)
            print(f"The code for '{user_input}' is {code}.")
        else:
            print("Please enter a single letter.")

if __name__ == "__main__":
    main()
