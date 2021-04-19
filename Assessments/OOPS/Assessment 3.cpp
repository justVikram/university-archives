/*
 Consider a Fitness App that list and describes various exercises with details. There are two types of exercises, home work-out and yoga. Each exercise has a name , id.
 Home work-out exercise demo are given by playing a video(simply display the name of the video file being played) and Yoga exercise demo is given by list of steps in the
 text. A user can download the app and view all the exercises and their demo. Then he/she can create a playlist and include some exercises in list. Write a program to
 display all list of exercises and playlist of the user.
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

//MARK:-

class EXERCISE
{
private:
    
    string name;
    int ID;
    
public:
    
    EXERCISE () {}
    
    EXERCISE (string name, int ID) : name (name), ID (ID) {}
    
    void showExercise ()
    {
        cout << "The exercise ID: " << ID << endl;
        cout << "The exercise name is: " << name << endl;
    }
    
};

//MARK:-

class YOGA : public EXERCISE
{
private:
    
    string StepsToDoYoga [10] = {"Breathe in", "Breathe out", "Perform Surya Namaskar"};
    
public:
    
    YOGA () {}
    
    YOGA (string name, int ID) : EXERCISE (name, ID) {}
    
    void showSteps ()
    {
        for (auto i : StepsToDoYoga)
            cout << i << endl;
    }
};

//MARK:-

class HOME_WORKOUT : public EXERCISE
{
private:
    
    string VideoFileName;
    
public:
    
    HOME_WORKOUT () {}
    
    HOME_WORKOUT (string name, int ID, string VideoFileName) : VideoFileName (VideoFileName), EXERCISE (name, ID) {}
    
    void playVideo ()
    {
        cout << "Now playing " << VideoFileName << endl;
    }
};

//MARK:-

class FITNESS_APP
{
private:
    
    EXERCISE * ListOfExercises = nullptr;
    HOME_WORKOUT * ListOfHomeWorkouts = nullptr;
    YOGA * ListOfYogaAsana = nullptr;
    EXERCISE * UserPlaylist = nullptr;
    static int NumberOfExercises;
    
public:
    
    FITNESS_APP () {}
    
    FITNESS_APP (HOME_WORKOUT * ListOfHomeWorkouts, YOGA * ListOfYogaAsana)
    {
        this->ListOfHomeWorkouts = new HOME_WORKOUT [10];
        this->ListOfExercises = new EXERCISE [10];
        
        int i = 0;
        
        for ( ; i < 7; i++)
            ListOfExercises [i] = this->ListOfHomeWorkouts [i] = ListOfHomeWorkouts [i];
        
        this->ListOfYogaAsana = new YOGA;
        *(this->ListOfYogaAsana) = *ListOfYogaAsana;

        ListOfExercises [i] = *ListOfYogaAsana;
    }
    
    void showExercises ()
    {
        for (int i = 0; i < 8; i++)
        {
            ListOfExercises [i].showExercise();
            cout << endl;
        }
            
    }
    
    void addToPlaylist (EXERCISE SomeExercise)
    {
        if (! UserPlaylist)
            UserPlaylist = new EXERCISE [10];
        
        UserPlaylist [NumberOfExercises++] = SomeExercise;
    }
    
    void showPlaylist ()
    {
        cout << "Showing user's playlist..." << endl;
        
        for (int i = 0; i < NumberOfExercises; i++)
        {
            UserPlaylist [i].showExercise();
            cout << endl;
        }
    }
    
    void showDemo (int ExerciseID)
    {
        ListOfHomeWorkouts [ExerciseID].playVideo();
    }
    
    ~FITNESS_APP ()
    {
        delete UserPlaylist;
        delete ListOfExercises;
        
        UserPlaylist = nullptr;
        ListOfExercises = nullptr;
    }
};
int FITNESS_APP :: NumberOfExercises = 0;

//MARK:-

int main (int argc, const char * argv [])
{
    ios_base::sync_with_stdio (false);
    
    HOME_WORKOUT * ListOfHomeWorkouts = new HOME_WORKOUT [10];
    
    ListOfHomeWorkouts [0] = HOME_WORKOUT ("Cycling", 1, "cycling.mp4");
    ListOfHomeWorkouts [1] = HOME_WORKOUT ("Running", 2, "cycling.mp4");
    ListOfHomeWorkouts [2] = HOME_WORKOUT ("Swimming", 3, "swimming.mp4");
    ListOfHomeWorkouts [3] = HOME_WORKOUT ("Jogging", 4, "jogging.mp4");
    ListOfHomeWorkouts [4] = HOME_WORKOUT ("Walking", 5, "walking.mp4");
    ListOfHomeWorkouts [5] = HOME_WORKOUT ("Stretching", 6, "stretching.mp4");
    ListOfHomeWorkouts [6] = HOME_WORKOUT ("Lifting", 7, "lifting.mp4");
    
    YOGA * YogaAsana = new YOGA ("Yoga", 8);
    
    FITNESS_APP Lifesum (ListOfHomeWorkouts, YogaAsana);
    
    while (1)
    {
        int ch;
        cout << "Enter choice:";
        cin >> ch;
        
        switch (ch)
        {
            case 1:
            {
                cout << "Showing all exercises..." << endl;
                Lifesum.showExercises();
                
                break;
            }
                
            case 2:
            {
                cout << "View demo" << endl;
                
                try
                {
                    int ExerciseID;
                    cout << "Enter exercise ID for which demo video  should play:";
                    cin >> ExerciseID;
                    
                    if (ExerciseID < 0 || ExerciseID > 7)
                        throw 1;
                    
                    Lifesum.showDemo (ExerciseID);
                }
                
                catch  (int a)
                {
                    if (a == 1)
                        cout << "Invalid Exercise ID. The ID does not refer to a home workout. Try again." << endl;
                }
                
                break;
            }
                
            case 3:
            {
                cout << "Add to playlist..." << endl;
                
                try
                {
                    int ExerciseID;
                    cout << "Enter Exercise ID:";
                    cin >> ExerciseID;
                    
                    if (ExerciseID < 1 || ExerciseID > 8)
                        throw 1;
                    
                    Lifesum.addToPlaylist(ListOfHomeWorkouts [ExerciseID - 1]);
                    
                    cout << "Added to your playlist!" << endl;
                }
                
                catch  (int)
                {
                    cout << "Invalid Exercise ID. The ID does not refer to any exercise. Try again." << endl;
                }
                
                break;
            }
                
            case 4:
            {
                cout << "View playlist..." << endl;
                
                Lifesum.showPlaylist();
                
                break;
            }
                
            case 5:
            {
                delete [] ListOfHomeWorkouts;
                delete YogaAsana;
            
                exit (0);
            }
        }
    }
}
