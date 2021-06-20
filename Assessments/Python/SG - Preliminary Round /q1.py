def gamingArray(arr):
    turn = 0  # If turn % 2 == 0, then BOB, else ANDY
    items_to_remove = []

    while len(arr) > 0:
        max_element = max(arr)  # 9
        index_of_max = arr.index(max_element)  # 3
        cur_len = len(arr)

        for i in range(index_of_max, cur_len):
            items_to_remove.append(arr[i])

        for remove_me in items_to_remove:
            arr.remove(remove_me)

        turn += 1
        items_to_remove.clear()

    if (turn - 1) % 2 == 0:
        return 'BOB'

    else:
        return 'ANDY'


if __name__ == '__main__':
    list = [1, 3, 5, 7, 9]
    print(gamingArray(list))
