  //static data member can be accesesd without craeting obj
    cout << Hero::timetoComplete << endl;
    // with creating obj
    Hero h1;
    cout << h1.timetoComplete <<endl;
    Hero h2;
    h2.timetoComplete= 40;
    cout << h2.timetoComplete <<endl;
    cout << h1.timetoComplete <<endl;
