int logo()
{
    int count_l=20;
    time_t start,stop;
    while(count_l)
    {
        system("cls");
        cout<<"\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(rand()%6)+10);
        cout<<"\n\n";
        cout<<"\n\t\t\t\t   **     **        **      ********  ********  **";
        cout<<"\n\t\t\t\t   **     **      **  **    ********  ********  **";
        cout<<"\n\t\t\t\t   *********    **      **     **     **        **";
        cout<<"\n\t\t\t\t   *********  **          **   **     ******    **";
        cout<<"\n\t\t\t\t   **     **    **      **     **     **        **";
        cout<<"\n\t\t\t\t   **     **      **  **       **     ********  ********";
        cout<<"\n\t\t\t\t   **     **        **         **     ********  ********";
        cout<<"\n\n";
        cout<<"\n\t\t\t**   ***       **   ******   **   ***       **   **   ********   **        **";
        cout<<"\n\t\t\t**   ***       **   ******   **   ***       **   **   ********   **        **";
        cout<<"\n\t\t\t**   ** **     **   **       **   ** **     **   **      **       **      **";
        cout<<"\n\t\t\t**   **  **    **   ****     **   **  **    **   **      **         **  **";
        cout<<"\n\t\t\t**   **    **  **   ****     **   **    **  **   **      **           **";
        cout<<"\n\t\t\t**   **      ****   **       **   **      ****   **      **           **";
        cout<<"\n\t\t\t**   **        **   **       **   **        **   **      **           **\n\n\n";
        Sleep(50);
        count_l--;
    }
    return 0;
}
