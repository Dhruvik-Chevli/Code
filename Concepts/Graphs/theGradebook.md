Annalise Keating is a professor of law in an ivy leauge college. After the summer exams she got her hands on a groups's gradebook.            
            
In total, the group has **p** students. All of the students received marks for **q** subjects. Each student got a mark from **1 to 9** (inclusive) for each subject.         
Let's consider a student excels at some subject, if there is no subject who got a higher mark for this subject. Let's consider a student successful, if there exists a subject he/she excels at.       
                
Your task is to find the number of successful students in the group.       

## Input Format
The first input line contains two integers **p** and **q** (1 &#8804; p,q &#8804; 100) - The number of student and the number of subjects, correspondingly.      
Next **p** lines each containing **q** characters describe the gradebook. Each character in the gradebook in a number from 1 to 9. Note that the marks in a rows are not separated by spaces.         

## Output format  
Print the single number - the number of successful students in the given group.         

## Sample input
```
3 3
223
232
112
```
## Sample output
```
2
```