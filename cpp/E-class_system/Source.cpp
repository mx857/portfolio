#include"Header.h"
#include"Course.h"
int main() {
	Student student1("69", "Xamidulla", "U2410255");
	Student student2("69", "Mirjalol", "U2410285");
	Student student3("69", "Farhod", "U2410253");
	Student student4("69", "Nazrulloh", "U2410189");
	Professor professor1("professor69", "Dokov", "U12345");
	Admin admin1("admin69", "Rustam", "U12346");
	User* users[] = { &student1, &professor1, &admin1,&student2,&student3,&student4 };
	int userCount = sizeof(users) / sizeof(users[0]);
	cout << "Welcome to INHA University Eclass\n";
	User* currentUser = nullptr;
	while (true) {
		currentUser = login(users, userCount);
		if (currentUser != nullptr) {
			cout << "\nLogin successful. Welcome, " << currentUser->getName() << "!\n";
			currentUser->displayMenu();
		}
		Course c("Calculus", "MATH101");
		c.addAssignment("Integration");

		// Student uploads
		string studentID = "U2410255";
		string submissionContent = "Here is my solution to the assignment...";
		c.submitAssignment("Some kind of calculus exercise", studentID, submissionContent);

		// Professor views it
		c.viewSubmission("Some kind of calculus exercise", studentID);
	}









}
