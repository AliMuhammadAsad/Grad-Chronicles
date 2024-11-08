import datetime


class Course:
    """ Holds information on a course and its assignments.
    """

    def __init__(self, title: str, hours: int, teacher: str, time: datetime.datetime) -> None:
        """Creates a course with the given information.

        Parameters:
        - self: mandatory reference to this object
        - title: name of the course
        - hours: total credit hours of the course
        - teacher: name of the instructor
        - time: date and time of the start of the first class

        Returns:
        none
        """
        self.title = title; self.hours = hours; self.teacher = teacher; self.time = time
        self.assignments = []

    def __str__(self) -> str:
        """Returns the string to be printed when this object is passed to str().

        The representation contains the course's title, hours, instructor name,
        and class time separated by newline.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        A string representation of this object.
        """
        return f"Course title: {self.title} \n Hours: {self.hours} \n Instructor: {self.teacher} \n Class time: {self.time}"

    def add_assignment(self, assignment: (str, int)) -> bool:
        """Returns the success status of adding assignment to the list of this course's
        assignments.

        assignment is represented by its title and weightage, e.g. ('HW1',
        10). It can be added to the list of assignments if adding the weightage
        does not cause the total weightage to exceed 100 and the list does not
        already contain an assignment with the same title. Otherwise it cannot
        and adding fails.

        Parameters:
        - self: mandatory reference to this object
        - assignment: a tuple containing the assignment name and weightage

        Returns:
        True if adding assignment succeeds, False otherwise.
        """
        weightage = 0
        for i in self.assignments:
            weightage = weightage + i[1]
            if i[0] == assignment[0] or weightage >= 100:
                return False
        self.assignments.append(assignment)
        return True

    def remove_assignment(self, assignment: str) -> bool:
        """Returns the success status of removing assignment from the list of this
        course's assignments.

        assignment is represented by its title, e.g. 'HW1'. It can be removed
        from the list of assignments if it already exists in the list. Otherwise
        it cannot and removing fails.

        Parameters:
        - self: mandatory reference to this object
        - assignment: the title of the assignment

        Returns:
        True if removing assignment succeeds, False otherwise.
        """
        for i in self.assignments:
            if i[0] == assignment:
                self.assignments.remove(i)
                return True
        return False

    def print_assignments(self) -> None:
        """Prints the assignments contained in the list of this course's assignments.

        Each assignment is printed on a new line in increasing order of
        weightage. Assignments with the same weightage are printed in any
        order. Each assignment is printed as its name and weightage separated by
        a tab character.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        none
        """
        for i in range(len(self.assignments) - 1):
            for j in range(len(self.assignments) - i - 1):
                if self.assignments[j][1] > self.assignments[j+1][1]:
                    self.assignments[j], self.assignments[j+1] = self.assignments[j+1], self.assignments[j]
        for i in self.assignments:
            print(f"Assignment: {i[0]} \t Weightage: {i[1]}")

    def is_complete(self) -> None:
        """Returns whether the course is complete, i.e. the total weightage of the
        stored assignments is 100.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        True if the course is complete, False otherwise.
        """
        total_weightage = 0
        for i in self.assignments:
            total_weightage = total_weightage + i[1]
        if total_weightage == 100:
            return True
        return False
