from src.course import Course
import datetime


def test_init():
    title, hours, instructor, time = 'DS 2', 3, 'SSR', \
        datetime.datetime(2022, 1, 11, hour=8, minute=30)
    course = Course(title, hours, instructor, time)
    course_str = str(course)
    assert title in course_str, \
        f'{title=} not in course'
    assert str(hours) in course_str, \
        f'{hours=} not in course'
    assert instructor in course_str, \
        f'{instructor=} not in course'
    assert str(time) in course_str, \
        f'{time=} not in course'
    assert (lines := course_str.count('\n')) == 3, \
        f'bad number of f{lines=}'


def test_add_assignment():
    title, hours, instructor, time = 'DS 2', 3, 'SSR', \
        datetime.datetime(2022, 1, 11, hour=8, minute=30)
    course = Course(title, hours, instructor, time)
    assert course.add_assignment(('HW', 30)) == True, \
        'Adding assignment should return True'
    assert course.add_assignment(('HW', 20)) == False, \
        'Adding duplicate assignment did not fail'
    assert course.is_complete() == False, \
        'Course is complete too soon.'
    assert course.add_assignment(('Project', 20)) == True, \
        'Adding assignment should return True'
    assert course.add_assignment(('Quiz', 30)) == True, \
        'Adding assignment should return True'
    assert course.add_assignment(('Exam', 20)) == True, \
        'Adding assignment should return True'
    assert course.is_complete() == True, \
        'Course is not complete at 100%.'
    assert course.add_assignment(('Lab', 10)) == False, \
        'Assignment should not be added after course is complete'


def test_remove_assignment():
    title, hours, instructor, time = 'DS 2', 3, 'SSR', \
        datetime.datetime(2022, 1, 11, hour=8, minute=30)
    course = Course(title, hours, instructor, time)
    course.add_assignment(('HW', 30))
    course.add_assignment(('Project', 20))
    course.add_assignment(('Quiz', 30))
    course.add_assignment(('Exam', 20))
    assert course.remove_assignment('HW') == True, \
        'Removing existing assignment failed.'
    assert course.remove_assignment('HW') == False, \
        'Removing missing assignment succeeded.'
    assert course.is_complete() == False, \
        'Incomplete course is considered complete.'
