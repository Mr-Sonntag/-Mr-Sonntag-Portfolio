def read_input(path):
    with open(path, 'r') as file:
        lines = file.read()

    return lines.split('\n')


def find_combination(sequence: list,start: int) -> int:
    combo = 0

    for step in sequence:
        if step.startswith('R'):
            start += int(step[1::])
            if start>99:
                start %= 100
        else:
            start -= int(step[1::])
            if start < 0:

                start = 100 - (abs(start)%100)

                if start == 100:
                    start = 0


        if start == 0:
            combo += 1



    return combo

def find_combination_part2(sequence: list,start: int) -> int:

#   Goal is to find how many clicks past or onto 0
#   If rotates past 0, combo +=1
#   If lands on 0, combo +=1

    combo = 0

    for step in sequence:

        if step.startswith('R'):

            start += int(step[1::])

            if start > 99:
                combo += start//100
                start %= 100
        else:
            zero = start == 0

            start -= int(step[1::])

            if start < 0:

                if zero:
                    combo += abs(start) // 100
                    start = 100 - (abs(start) % 100)

                else:
                    combo += abs(start) // 100 + 1
                    start = 100 - (abs(start) % 100)

                if start == 100:
                    start = 0
            elif start == 0:
                combo += 1

    return combo


def main():
    sequence = read_input('.\\input')
    dial = 50
    combination = find_combination(sequence,dial)
    second_sequence = read_input('.\\my_input')

    combination = find_combination_part2(sequence,dial)

    print(f"Combination: {combination}")


    return 0

if __name__ == "__main__":
    main()