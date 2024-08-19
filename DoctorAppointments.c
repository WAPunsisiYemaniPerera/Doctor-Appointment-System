#include <stdio.h>
#include <stdlib.h>

// global variable
struct appointment {
    int patient_number;
    char patient_name[100];
    char doctor_name[100];
    char appointment_date[20];
    char appointment_time[10];
    struct appointment *next;
};

struct appointment *head = NULL;

// Function to check if a patient number already exists
int isPatientNumberExists(int patientNumber) {
    struct appointment *current = head;
    while (current != NULL) {
        if (current->patient_number == patientNumber) {
            return 1; // Patient number already exists
        }
        current = current->next;
    }
    return 0; // Patient number does not exist
}

int main() {
    // declare the variables
    int choice;
    struct appointment *current, *previous, *newappointment;

    do {
        // show the menu
        printf("**********************************************************************************\n");
        printf("*                                                                                *\n");
        printf("*              Doctor Appointments in Lanka Hospitals-Sri Lanka                  *\n");
        printf("*                                                                                *\n");
        printf("**********************************************************************************\n");

        printf("*  ---OPTIONS---                                                                 *\n");
        printf("*  1)Insert a new Appointment                                                    *\n");
        printf("*  2)Delete an Appointment                                                       *\n");
        printf("*  3)Search for an Appointment                                                   *\n");
        printf("*  4)Display all the Appointments                                                *\n");
        printf("*  5)Exit                                                                        *\n");
        printf("*                                                                                *\n");
        printf("**********************************************************************************\n");

        printf("\n\n");

        // get the choice
        printf("Enter the choice to continue - ");
        scanf("%d", &choice);
        printf("\n");

        // get into the switch
        switch (choice) {
            case 1: {
                newappointment = (struct appointment *)malloc(sizeof(struct appointment));

                // get the data
                printf("Patient's number - ");
                scanf("%d", &newappointment->patient_number);

                // Check if the patient number already exists
                if (isPatientNumberExists(newappointment->patient_number)) {
                    printf("Patient number already exists. Please choose a different number.\n\n");
                    free(newappointment);
                    break;
                }

                printf("Patient's name - ");
                scanf("%s", newappointment->patient_name);

                printf("Doctor's name - ");
                scanf("%s", newappointment->doctor_name);

                printf("Appointment Date - ");
                scanf("%s", newappointment->appointment_date);

                printf("Appointment Time - ");
                scanf("%s", newappointment->appointment_time);

                newappointment->next = NULL;

                printf("\n");

                if (head == NULL) {
                    head = newappointment;
                } else {
                    current = head;

                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newappointment;
                }
                break;
            }

            case 2: {
                // declare the variables
                int patient_no;

                printf("Enter the Patients's Number that you want to delete - ");
                scanf("%d", &patient_no);

                current = head; // first assign the current as head to go to the first element of the list
                previous = NULL; // assign the previous node's pointer as 0

                while (current != NULL && current->patient_number != patient_no) {
                    previous = current;
                    current = current->next;
                }

                if (current == NULL) {
                    printf("THE APPOINTMENT NOT FOUND!!!");
                } else {
                    if (previous == NULL) {
                        head = current->next;
                    } else {
                        previous->next = current->next;
                    }

                    printf("%d is DELETED!!!", patient_no);

                    free(current);
                }

                break;
            }

            case 3: {
                // declare the variables
                int patient_no;

                // get the no that the user wants to delete
                printf("Enter the patient's Number that you want to search - ");
                scanf("%d", &patient_no);

                current = head;

                while (current != NULL && current->patient_number != patient_no) {
                    current = current->next;
                }

                if (current == NULL) {
                    printf("NOT FOUND THE APPOINTMENT!!!\n\n");
                    // Allow the user to try again
                } else {
                    printf("FOUND THE APPOINTMENT AND HERE ARE THE DETAILS\n\n");
                    printf("* Patient's Number - %d\n", current->patient_number);
                    printf("* Patient's Name - %s\n", current->patient_name);
                    printf("* Doctor's Number - %s\n", current->doctor_name);
                    printf("* Date of the Appointment - %s\n", current->appointment_date);
                    printf("* Time of the Appointment - %s\n\n", current->appointment_time);
                }

                break;
            }

            case 4: {
                // declare a temporary pointer to iterate through the linked list
                struct appointment *temp = head;

                while (temp != NULL) {
                    printf("*******Appointment**********\n");
                    printf("* Patient's Number - %d\n", temp->patient_number);
                    printf("* Patient's Name - %s\n", temp->patient_name);
                    printf("* Doctor's Name - %s\n", temp->doctor_name);
                    printf("* Date of the Appointment - %s\n", temp->appointment_date);
                    printf("* Time of the Appointment - %s\n", temp->appointment_time);
                    printf("\n");

                    temp = temp->next;
                }

                // free the temporary pointer
                // Note: You don't need to free(temp) because temp is just a pointer that iterates through the list
                // The actual memory allocation is handled by malloc and should be freed when deleting nodes.

                break;
            }
        }
    } while (choice != 5);

    return 0;
}
