/*
 * functions.h
 *
 *  Created on: Jul 22, 2024
 *      Author: abdel
 */

#ifndef STUDENT_FUNCTIONS_H_
#define STUDENT_FUNCTIONS_H_
#include "stdio.h"
#include "Platforms_Type.h"
#include "fifo.h"
#include "myFunctions.h"


extern void add_student_from_file(FIFO_Buff_t * Buffer);
extern void add_student_manually(FIFO_Buff_t * Buffer);/*Take student data manually from the user directly from terminal*/
extern void find_student_roll_number(FIFO_Buff_t * Buffer);/*Search for student by his roll number*/
extern void find_student_first_name(FIFO_Buff_t * Buffer);
extern void find_student_course(FIFO_Buff_t * Buffer);
extern void total_number_of_students(FIFO_Buff_t * Buffer);/*Print total number of students in the system , print number of available places to add students and
 * Max number of students you can add
 */
extern void delete_student(FIFO_Buff_t * Buffer);/*delete student*/
extern void update_student(FIFO_Buff_t * Buffer);/*update student*/
extern void show_all(FIFO_Buff_t * Buffer);/*Print all students data*/

#endif /* STUDENT_FUNCTIONS_H_ */
