#include<stdio.h>

int main()
{
      int fragments[10], block[10], file[10], m, n, number_of_blocks, number_of_files, temp, lowest = 10000;
      static int block_arr[10], file_arr[10];
      printf("\nEnter the Total Number of Blocks:\t");
      scanf("%d", &number_of_blocks);
      printf("\nEnter the Total Number of Files:\t");
      scanf("%d", &number_of_files);
      printf("\nEnter the Size of the Blocks:\n");
      for(m = 0; m < number_of_blocks; m++)
      {
            printf("Block No.[%d]:\t", m + 1);
            scanf("%d", &block[m]);
      }
      printf("Enter the Size of the Files:\n");
      for(m = 0; m < number_of_files; m++)
      {
            printf("File No.[%d]:\t", m + 1);
            scanf("%d", &file[m]);
      }
      for(m = 0; m < number_of_files; m++)
      {
            for(n = 0; n < number_of_blocks; n++)
            {
                  if(block_arr[n] != 1)
                  {
                        temp = block[n] - file[m];
                        if(temp >= 0)
                        {
                              if(lowest > temp)
                              {
                                    file_arr[m] = n;
                                    lowest = temp;
                              }
                        }
                  }
                  fragments[m] = lowest;
                  block_arr[file_arr[m]] = 1;
                  lowest = 10000;
            }
      }
      printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment");
      for(m = 0; m < number_of_files && file_arr[m] != 0; m++)
      {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", m, file[m], file_arr[m], block[file_arr[m]], fragments[m]);
      }
      printf("\n");
      return 0;
}
