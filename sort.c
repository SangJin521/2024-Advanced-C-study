#include "sort.h"

/* [TODO]
   Implement function compareByName
*/
int compareByName(Student a, Student b) {
   return strcmp(a.name, b.name);
}

/* [TODO]
   Implement function compareById
*/
int compareById(Student a, Student b) {
   return a.id - b.id;
}

/* [TODO]
   Implement function quickSort
*/
void quickSort(Student *students, int length, int (*compare)(Student, Student)) {
   if (length <= 1) {
      return;
   }

   Student pivot = students[length/2];
   int low = 0;
   int high = length - 1;

   while (low <= high) {
      while (compare(students[low], pivot) < 0) {
         low++;
      }
      while (compare(students[high], pivot) > 0) {
         high--;
      }
      if (low <= high) {
         swap(&students[low], &students[high]);
         low++;
         high--;
      }
   }

   quickSort(students, high + 1, compare);
   quickSort(students + low, length - low, compare);
}
