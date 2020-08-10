import sys

def main():
    # check command line args
    if len(sys.argv) == 3:
        # Verify command line args coercible to ints
        if not (sys.argv[1].isdigit() & sys.argv[2].isdigit()):
            print('start and end must be integers')
            return 1
        else:
            start = int(sys.argv[1])
            end = int(sys.argv[2])

    elif len(sys.argv) == 1:
        # Prompt user for integer input (repeat prompt until input is valid)
        start = ''
        end = ''
        while not start.isdigit():
            start = input("Enter a starting number: ")
        while not end.isdigit():
            end = input("Enter an ending number: ")

        start = int(start)
        end = int(end)
    else:
        print('Usage: find_primes.py [start_num] [end_num]')
        return 1

    if (start < 1) or (end < 1):
        print('Start and end must be positive integers')
        return 1

    if end < start:
        print('Error: End must be greater than start')
        return 1
    
    print(f"Prime numbers between {start} and {end}:")
    prime_count = 0

    if start < 2:
        start = 2

    for n in range(start, end + 1):
        # check only odd numbers (check 2 later as all evens are divisible by 2)
        for x in range(2, n):
            if n % x == 0:
                break
        else:
            # loop ended without breaking: n is prime
            prime_count += 1
            print(n)

    # Fallback output if no primes are found
    if prime_count == 0:
        print('None')            

if __name__ == "__main__":
    main()