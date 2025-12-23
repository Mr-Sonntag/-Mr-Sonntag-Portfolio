

def problem_input():
    path = ".\\input"
    with open(path, 'r') as f:
        lines = f.read()
    return list(lines.split('\n'))

def determine_total_joltage(banks: list)-> int:
    total_joltage = 0

    for bank in banks:
        battery1 = "0"
        battery2 = "0"
        for battery in bank:
            if int(battery2+battery) > int(battery1+battery2):
                battery1 = battery2
                battery2 = battery
            elif int(battery)>int(battery2):
                battery2 = battery

        total_joltage += int(battery1+battery2)

    return total_joltage


def determine_total_joltage_part2(banks: list, batteries: int)-> int:
    total_joltage = 0
    for bank in banks:
        batts= list(bank)

        result = ""
        # print(f"bank {bank}: ")
        for i in range(batteries):
            bank_len = len(batts)

            if i == batteries-1:
                max_batt = max(batts)
                k = 0
            else:
                k = bank_len-batteries+i
                max_batt = max(batts[:k+1])

            result+= max_batt
            index = batts.index(max_batt)
            # print(f"Batts: {"".join(batts)}. Max batt: {max_batt} at index: {index}, adjusted by {bank_len-k}")

            batts = batts[index+1:]

        total_joltage += int(result)

    return total_joltage










    return total_joltage


def main():
    banks = problem_input()

    total_joltage_part1 = determine_total_joltage(banks)
    print(f"Total Joltage for part 1: {total_joltage_part1}")

    batteries = 12
    total_joltage_part2 = determine_total_joltage_part2(banks, batteries)
    print(f"Total Joltage for part 2: {total_joltage_part2}")



if __name__ == "__main__":
    main()