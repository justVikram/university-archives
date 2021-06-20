def gradingStudents(grades):
    new_grades = []
    for grade in grades:
        dividend = int(grade / 5)
        dividend += 1
        round_up = dividend * 5

        if ((round_up) - grade < 3 and grade >= 38):
            new_grades.append(round_up)
        else:
            new_grades.append(grade)

    return new_grades


if __name__ == '__main__':
    gradingStudents([73, 67, 38, 33])
