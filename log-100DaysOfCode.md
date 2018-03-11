# 100 Days Of Code - Log

## Day 1: March 1, 2018

**Today's Progress:** Working on the project space and structure. Decided brushing up on CMake, so I am preparing build script.

**Thoughts:** I am not really sure if preparing the project counts toward "coding", but it is an important part of any software project so I will act like it is.

## Day 2: March 2, 2018

**Today's Progress:** Added logging ability using spdlog library

**Thoughts:** It was a long day and I am quite tired. I will sto for today, as the code is running circles in front of my eyes.

## Day 3: March 3, 2018

**Today's Progress:** Created a wrapper for spdlog for uniform use throughout the project.
Testing the OpenGL initialization. Created a window. Wrapped it into a class.

**Thoughts:** Refactoring might be tedious sometimes, but it pays off.

## Day 4: March 4, 2018

**Today's Progress:** Started working on a data model. First step is the location object.

**Thoughts:** To better understand the both square-based and hexagon-based models in a 3D space, I need to list pros and cons (some paper-modeling will take place). Decided to go with point-based objects that define a location within the proximity of a point, as it seems more natural. This will eventually result in some form of conversion later, if I ever introduce a board-style model.

## Day 5: March 10, 2018

**Today's progress:** Starting working on the ncurses implementation for simple presentation (console). Created some interfaces for presentation purposes.

**Thoughts:** The console approach is completely different than GL, so I expect a lot of refactoring in the IPresentation interface before devising a more or less agnostic approach to this.

## Day 6: March 11, 2018

**Today's progress:** Introduced namespaces into the presentation model. Added basic unit tests. Started Window class.

**Thoughts:** Creating the Window class implies some other classes as well (Point, Size, Rectangle, etc.) Those classes must be covered with unit tests as they will serve as a base for multiple functionalities. Is there a way to unit test the visible screen result (research)?