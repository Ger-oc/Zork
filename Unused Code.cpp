//
// Created by spike on 17/04/2021.
//

/*
 * Creating objects as rooms
 *
 *
 * Hallway* ha = new Hallway();
 ha->setExits(office, bathroom, NULL, bedroom );
 ha->addItem(new Item("bust", 1, 1.0));
 ha->addItem(new Item ("book case", 1, 1.0));
 ha->addItem(new Item("umbrella stand", 1, 1.0));
 ha->addItem(new Item("paper", 1, 1.0));
 ha->shortDescription("hallway");
 ha->currentRoom(1);
 string test1 = ha->displayItem();
// cout << test1 << endl;


    Bedroom* be = new Bedroom();
    be->setExits(NULL, NULL, hall, NULL);
    be->addItem(new Item("magazine", 1, 1.0));
    be->addItem(new Item("bed", 1, 1.0));
    be->addItem(new Item("suitcase", 1, 1.0));
    be->addItem(new Item("suncream", 1, 1.0));
    be->addItem(new Item("dildo", 1, 1.0));
    be->addItem(new Item("painting", 1, 1.0));
    be->addItem(new Item("marbles", 1, 1.0));
    be->currentRoom(2);
    string test = be->displayItem();
    //cout << test << endl;


    Bathroom* ba = new Bathroom();
    ba->setExits(NULL, NULL, hall, NULL);
    ba->addItem(new Item("toilet", 1, 1.0));
    ba->addItem(new Item ("gold bidate", 1, 1.0));
    ba->addItem(new Item ("mirror", 1, 1.0));
    ba->addItem(new Item ("screwdriver", 1, 1.0));
    ba->addItem(new Item ("shampoo", 1, 1.0));
    ba->currentRoom(3);
    string test2 = ba->displayItem();
    // cout << test2 << endl;

      Office* offic = new Office();
    offic->setExits(NULL, NULL, hall, NULL);
    offic->addItem(new Item("money", 1, 1.0));
    offic->addItem(new Item("cat",1, 1.0));
    offic->addItem(new Item("gold Buddha",1, 1.0));
    offic->currentRoom(4);
    string test3 = offic->displayItem();
    //cout << test3 << endl;
    */




/*
 *
 * From messing about with inventory class and vectors
 *
 * validItems.push_back("Magazine"); // from bed side locker
    validItems.push_back("bottle");  // from globe bar
    validItems.push_back("torch");  // torch to look under bed with
    validItems.push_back("book");    // found in suitcase in closet
    validItems.push_back("lighter"); // found in suitcase clothes
    validItems.push_back("sunscreen");  // found in suitcase usless item that they can pick up
    validItems.push_back("marbles");  //marbles from behind painting
    validItems.push_back("key"); // comes from cabinet
    validItems.push_back("umbrella");  //comes from umbrella stand in hallway
    validItems.push_back("book");   // to be used to open bok case drawer in hallway
    validItems.push_back("paper"); // paper from book case with a bit of the code
    validItems.push_back("screwdriver"); // to remove mirror
    validItems.push_back("toothbrush");  // from bathroom vanity useless
    validItems.push_back("razor"); // from bathroom vanity useless
    validItems.push_back("");


   went well off course with this
string Command::getSecondWord(){     NOT WORKING

	for (int i = 0; i < validItems.size(); ++i) {

		if(validItems[i].compare(getSecondWord()) == 0)
			ItemsOnPerson.push_back(validItems[i]);
	}
}
*/