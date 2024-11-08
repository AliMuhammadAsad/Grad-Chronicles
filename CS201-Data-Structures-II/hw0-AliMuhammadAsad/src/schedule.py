from course import Course


class Schedule:
    """ Contains courses.
    """

    def __init__(self, courses: [Course] = []) -> None:
        """Creates a schedule containing courses.

        Parameters:
        - self: mandatory reference to this object
        - courses: list of Course objects.

        Returns:
        none
        """
        self.courses = courses

    def __str__(self) -> str:
        """Returns the string to be printed when this object is passed to print().

        The representation contains each course separated by two newline
        characters. The courses are ordered by the start time of their
        classes. The last line indicates the total number of credit hours.

        Parameters:
        - self: mandatory reference to this object

        Returns:
        A string representation of this object.
        """
        for i in range(len(self.courses)-1):
            for j in range(len(self.courses) - i - 1):
                if self.courses[j].time > self.courses[j+1].time:
                    self.courses[j], self.courses[j+1] = self.courses[j+1], self.courses[j]
        total_credits = 0
        for i in self.courses:
            total_credits = total_credits + i.hours
        val = str()
        for i in self.courses:
            val = i.name + "\n\n"
        val = val + str(total_credits)
        return val

    def add_course(self, course: Course) -> bool:
        """Returns the success status of adding course to the schedule.

        course is successfully added if it does not conflict with an existing
        course. Otherwise, adding fails.

        Parameters:
        - self: mandatory reference to this object
        - course: course to be added

        Returns:
        True if adding course succeeds, False otherwise.
        """
        for i in self.courses:
            if course.title == i.title:
                return False
        self.courses.append(course)
        return True

    def remove_course(self, course: str) -> bool:
        """Returns the success status of removing course from the schedule.

        course is represented by its title. It is successfully removed if the
        schedule contains a course of the same title. Otherwise, removing fails.

        Parameters:
        - self: mandatory reference to this object
        - course: title of course to be removed

        Returns:
        True if removing course succeeds, False otherwise.
        """
        for i in self.courses:
            if course == i.title:
                self.courses.remove(i)
                return True
        return False
