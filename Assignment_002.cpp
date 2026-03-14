#include <iostream>
 using namespace std;

    void analyze(int *arr, int students, int subjects, int stride)
{
    int i, j;
    int highest = *arr;

    cout<<"\nGrade Matrix:\n";

        for (int i = 0; i < students; i++)
        {
            for(int j = 0; j < subjects; j++)
            {
                int value = *(arr + i * stride + j);
                cout<< value << "\t";

                if (value > highest)
                    {
                    highest = value;
                }
            }
            cout<<endl;
        }

        cout<< "\nAverage of Each Student:\n";

        for (int i = 0; i < students; i++)
            {

            int sum = 0;
            for ( int j = 0; j < subjects; j++)
                {
                sum = sum + *(arr + i * stride + j);
            }
            float average = (float)sum / subjects;
            cout << "Student[" << i + 1 << "]:" << average << endl;
        }
        cout<<"\nThe Highest Grade is: "<< highest << endl;
}

        int main () {

            int students, subjects;
            int grades[20][20];
            int i, j;

            cout<<"Enter The Number of Students:";
            cin>>students;
            cout<<"Enter The Number of Subjects:";
            cin>>subjects;

            cout<<"\nEnter The Grades:\n";

                for ( int i = 0; i < students; i++){
                    for (int j = 0; j < subjects; j++)
                        {
                        cout<<"\nStudent[" << i+1 << "]Subject[" << j+1 << "]:";
                        cin>>grades[i][j];
                    }

                }
                analyze(&grades[0][0], students, subjects, 20);



                return 0;
        }
