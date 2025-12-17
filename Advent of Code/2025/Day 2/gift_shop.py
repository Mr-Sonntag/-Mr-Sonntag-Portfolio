
def read_input(path):
    with open(path, 'r') as file:
        lines = file.read()

    return lines

def find_factors(n):

    factors = [i for i in range(1,n+1) if n % i == 0]

    return factors

def is_prime(n):

    #Special case:
    if n == 1:
        return False

    if n == 2:
        return True

    if n % 2 == 0:
        return False

    i = 3

    while i * i <= n:
        if n % i == 0:
            return False
        i += 2

    return True

def count_prime_ranges(item_ids):
    total = 0
    total_primes = 0

    for item_id in item_ids:
        lower, upper = item_id.split("-")

        total+=1
        total_primes+=1 if is_prime(len(lower)) and is_prime(len(upper)) else 0

    return total, total_primes

def sum_invalid_ids(item_ids: list[str])-> int:
    total = 0

    for item_id in item_ids:
        lower,upper = item_id.split('-')

        lower_length = len(lower)
        upper_length = len(upper)

        difference = upper_length - lower_length

        if difference == 0:
            if lower_length % 2 == 1:
                continue
            #Code for finding invalid ids
            for i in range(int(lower), int(upper)+1):
                if str(i)[0:lower_length//2] == str(i)[lower_length//2:]:
                    total += i
        elif lower_length % 2 == 0: #Start at lower range end at 10^(upper_length-1)
            for i in range(int(lower), pow(10, upper_length-1)):
                if str(i)[0:lower_length//2] == str(i)[lower_length//2:]:
                    total += i
        else:
            #Start at 10^(upper_length-1) to upper_range
            for i in range(pow(10,upper_length-1), int(upper)+1):
                if str(i)[0:upper_length//2] == str(i)[upper_length//2:]:
                    total += i

    return total


def sum_invalid_ids_part2(item_ids)-> int:

    def sum_prime_ranges(lower, upper):
        lower_length = len(str(lower))
        upper_length = len(str(upper))

        print(f"Range: ({lower},{upper})")

        if int(str(lower)[0] * lower_length) > (int(lower)):
            i = int(str(lower)[0])
        else:
            i = int(str(lower)[0]) + 1

        if upper_length > lower_length:
            total = 0

            total += sum(int(str(u) * lower_length)
                   for u in range(i, 10))

            total += sum(int(str(u) * upper_length)
                   for u in range(1, int(str(upper)[0]) + 1)
                         if int(str(u) * upper_length) < int(upper))

            return total


        return sum(int(str(u) * lower_length)
                   for u in range(i, int(str(upper)[0]) + 1)
                   if int(str(u) * lower_length) < int(upper))

    def sum_non_prime_range(lower, upper):
        lower_length = len(str(lower))
        upper_length = len(str(upper))
        total = 0

        print(f"Range: ({lower},{upper})")

        if (lower_length == 1):
            lower = 10
            lower_length = 2

        factors = find_factors(lower_length)
        # print(f"The length of ranges are ({lower_length}, {upper_length}) and the factors are {factors}.")

        for i in range(int(lower), int(upper)+1):
            for factor in factors[:-1]:
                if str(i).count(str(i)[:factor]) == lower_length//factor:
                    print(f"Invalid ID: {i}")
                    total += i
                    break

        return total
    #End of helper functions
    total = 0

    for item_id in item_ids:
        lower,upper = item_id.split('-')
        lower_length = len(lower)
        upper_length = len(upper)

        # print(f"Range: ({lower},{upper}). \nTotal Before: {total}")
        prev_total = total

        #If the range's length is the same and the length is prime,
        #then all invalid ids in range are consecutive numbers of
        #the range's length
        #Sums invalid ids for range lengths: 2,3,5,7,11,etc. primes
        if is_prime(lower_length) and is_prime(upper_length):
            prev_total = total
            total += sum_prime_ranges(lower, upper)

        elif is_prime(int(lower_length)):
            prev_total = total
            total += sum_prime_ranges(lower, pow(10, upper_length-1))
            #Total the range that isn't prime ([pow(10,upper_length-1),upper])
            total += sum_non_prime_range(pow(10,upper_length-1), upper)

        elif is_prime(int(upper_length)):
            prev_total = total
            total += sum_prime_ranges(pow(10, upper_length-1), upper)
            #Total the range that isn't prime ([lower,pow(10, lower_length-1)])
            total += sum_non_prime_range(lower, pow(10, upper_length-1))

        else:
            total += sum_non_prime_range(lower, upper)

        print(f"Before-After: {prev_total}-{total}. Difference: {total-prev_total}")


    return total

def main():
    # ids = (i for i in str(read_input('.\\input')).split(','))
    #
    # sum = sum_invalid_ids(ids)

    # print(sum)

    ids = (i for i in str(read_input('.\\input')).split(','))

    # total, primes = count_prime_ranges(ids)
    #
    # print(f"Total ids: {total}\nTotal primes: {primes}")

    sum = sum_invalid_ids_part2(ids)

    print(sum)

    # for item in ids:
    #     lower, upper = item.split('-')
    #     print(f"Lower length: {len(lower)} Prime: {is_prime(len(lower))}. Upper length: {len(upper)} Prime: {is_prime(len(upper))}")







if __name__ == "__main__":
    main()