import io
import os
import sys

# sieve of eratosthenes


def sieve_of_eratosthenes(n: int):
    """Return a list of prime numbers less than or equal to n."""
    if n < 2:
        return []
    else:
        # create a list of all numbers from 2 to n
        numbers = list(range(2, n + 1))
        # create a list of prime numbers
        primes = []
        # while there are numbers in the list
        while numbers:
            # remove the first number from the list and add it to the list of primes
            primes.append(numbers.pop(0))
            # remove all multiples of the last prime number from the list
            numbers = [number for number in numbers if number %
                       primes[-1] != 0]
        return [str(p) for p in primes]


input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input().decode())
sys.stdout.write(" ".join(sieve_of_eratosthenes(n)))
