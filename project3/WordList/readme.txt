Doxygen Link:  https://csit.kutztown.edu/~tpasq515/csc237/project3/html/index.html

Q: You must choose a sequential container from the STL for that subclass. In your readme
you must name the containers that should be considered and why you made your
choice.

A: For project 3 I have decided to use the vector as my STL container. I used this container
for many reasons. The first reason is because I used it in the first project and it gave me
no problems making for easy and quick implementation. The second reason is because it is a
dynamic array which means that items can continiously be added onto it, it has a built in
indexing feature which makes for simple access to specific position even with the use of 
pointers, and lastly it provides relatively fast insertion and deletion of elements at the
end of the list. One of the containers that I considered was the List container. This 
container is a dynamic doubly linked list which is good as its dymanic, however, there is
no direct access to specific points making searching for elements a linear process. The list 
does provide constant time insert and erase operations, but since there is no direct access to 
elements I decided to pass on the container. Another container that I considered to use was the 
foward_list. The foward_list is similar to the list container, however, instead of using a doubly 
linked list, it uses a singular one. This one was considered more than the list container as it 
has pretty much every single one of the good features that the list has, but uses less resources 
because it is a singly linked list. The only reason that I did not use it is because I would be 
unable to access specific indexes when needed. Overall, the vector is a very user friendly container
that has more positive properties compared to both the list and the forward_list.
