int PROGRESSBAR()
{
    int i,gd=DETECT,gm;
    initwindow(600,400,"Submitting order",500,0);
    setcolor(WHITE);
    for(i=5;i<525;i++)
    {
        line(25+i,170,25+i,200);
    }
    for(i=5;i<525;i++)
    {
        setcolor(GREEN);
        line(25+i,170,25+i,200);
        delay(1);
        setcolor(rand()%16);
        settextstyle(SMALL_FONT,HORIZ_DIR,16);
        outtextxy(175,220,"SUBMITTING...");
        delay(3);
    }
    closegraph();
    return 0;
}
