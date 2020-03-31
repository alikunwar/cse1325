#include "mainwin.h"
#include <iostream> // for std::cerr logging
#include <string.h>
#include <sstream>

#include "entrydialog.h"

Mainwin::Mainwin() : store{nullptr} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(600, 200);
    set_title("ELSA");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);
	

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    
    //         Quit
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //                V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //           customer
    // Append customer to the View menu
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_view_customer_click();});
    viewmenu->append(*menuitem_customer);
	
	//           peripheral
    // Append peripheral to the View menu
    Gtk::MenuItem *menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_peripheral", true));
    menuitem_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_peripheral);

    //           desktop
    // Append desktop to the View menu
    Gtk::MenuItem *menuitem_desktop = Gtk::manage(new Gtk::MenuItem("_desktop", true));
    menuitem_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
    viewmenu->append(*menuitem_desktop);
	
	//           order
    // Append order to the View menu
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_order", true));
    menuitem_order->signal_activate().connect([this] {this->on_view_order_click();});
    viewmenu->append(*menuitem_order);
	
	
	
	//              I N S E R T
    // Create a Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //           Customer
    // Append Customer to the Insert menu
    Gtk::MenuItem *menuitem_Customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_Customer->signal_activate().connect([this] {this->on_insert_customer_click();});
    insertmenu->append(*menuitem_Customer);
	
	//           Peripheral
    // Append Peripheral to the Insert menu
     Gtk::MenuItem *menuitem_Peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_Peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
    insertmenu->append(*menuitem_Peripheral);

    //           Desktop
    // Append Desktop to the Desktop menu
    Gtk::MenuItem *menuitem_Desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_Desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
    insertmenu->append(*menuitem_Desktop);
	
	//           Order
    // Append Order to the Insert menu
    Gtk::MenuItem *menuitem_Order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_Order->signal_activate().connect([this] {this->on_insert_order_click();});
    insertmenu->append(*menuitem_Order);
	
	//             H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

   

    //           About
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);
	
	// Data   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);
	
	store = new Store;
    
    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for  messages
	
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    

	vbox->show_all(); // make everything visible 

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

// COMBINED observer / callback

void Mainwin::on_quit_click()
{
	close();
}

void Mainwin::on_view_peripheral_click()
{
	std::ostringstream oss;
	std:: string x = "<b> Peripherals </b>";
	 oss<< x <<"\n";
	 set_data(oss.str());
	 
	for(int i=0; i<store->num_options(); ++i) 
	{
    oss<<"\n"<< i << ") " << store->option(i) << "\n";
    }
	set_data(oss.str());
	
}

void Mainwin::on_view_desktop_click()
{
	
	std::ostringstream oss;
	
	
	std:: string x = "<b> Products </b>";
	 oss<< x <<"\n";
	 set_data(oss.str());
	 
    for (int i = 0; i < store->num_desktops(); ++i)
	{
       oss <<"\n" << i << ") " << store->desktop(i) << "\n";
	}

    set_data(oss.str());
}


void Mainwin::on_view_order_click()
{
	
	std::ostringstream oss;
	
	std:: string x = "<b> Orders </b>";
	 oss<< x <<"\n";
	 set_data(oss.str());
	 
    for (int i = 0; i < store->num_orders(); ++i)
	{
    oss <<"\n"<< i << ") " << store->order(i) << "\n";
	}

    set_data(oss.str());
}


void Mainwin::on_view_customer_click()
{
	 std::ostringstream oss;
	 
	 std:: string x = "<b>Name of customer(phone number, email)</b>";
	 oss<< x <<"\n";
	 set_data(oss.str());
	 
	for(int i=0; i< store->num_customers(); ++i) 
	{
    oss<< "\n"<< i << ") " << store->customer(i);
	}
	set_data(oss.str());
	
   
}

void Mainwin::on_insert_peripheral_click()
{
  std::string name = get_string("Name of the peripheral");
  double cost = get_double(" Cost in dollar $");
  
  Options option{name, cost};
  store->add_option(option); 
 }	
	


void Mainwin::on_insert_order_click()
{
	 std::ostringstream oss;
     for(int i=0; i<store->num_customers(); ++i) 
                oss<< i << ") " << store->customer(i) << '\n';
            int customer = get_int("Number of line of the customer");
            
           

            int order = store->new_order(customer);

 while(true) {
                for(int i=0; i<store->num_desktops(); ++i) 
                    oss << i << ") " << store->desktop(i) << '\n';
                 int desktop = get_int("Which Desktop? (-1 to exit)");
                
                
                if(desktop == -1) break;
                store->add_desktop(desktop, order);
            }
oss << "\n++++ Order Placed ++++\n" << store->order(order);

   
}




void Mainwin::on_insert_desktop_click()
{
    int desktop = store->new_desktop();
	std::ostringstream oss;

    while (true)
    {
        oss << "\n"
                  << store->desktop(desktop) << "\n\n";
        for (int i = 0; i < store->num_options(); ++i)
            oss << i << ") " << store->option(i) << "\n";
        int option;
        option = (int)Mainwin::get_double("\nAdd which peripheral (-1 when done)? ");
        if (option == -1)
            break;
        try
        {
            store->add_option(option, desktop);
        }
        catch (std::exception &e)
        {
            std::cerr << "#### INVALID OPTION ####\n\n";
        }
    }
    
}



void Mainwin::on_insert_customer_click()
{
   std::string name = get_string("Name of the customer");
   std::string phone = get_string("Phone number (xxx-xxx-xxxx) ");
   std::string email= get_string("Email of the customer (xxx@domain.com) ");
   Customer customer{name, phone, email};
   store->add_customer(customer);
     
}


void Mainwin::on_about_click()
 {
     Glib::ustring alisa = R"(
<span size='24000' weight='bold'>ELSA</span>
<span size='large'>Copyright on March 2020 by Alisha Kunwar - CC BY 4.0</span>
The Exceptional Laptops and Supercomputers Always (ELSA) store offers the coolest (ahem) deals in computing technology for savvy computer geeks and their lucky friends.)";
    Gtk::MessageDialog{*this, alisa, true}.run(); // 'true' as 3rd parameter enables Pango markup
} 

	
	
	


std::string Mainwin::get_string(std::string prompt)
{
	EntryDialog ed{*this, prompt};
	ed.set_text("");
	ed.run();
	return ed.get_text();
	
	
}


double Mainwin::get_double(std::string prompt)
{
	EntryDialog ed{*this, prompt};
	ed.set_text("");
	ed.run();
	return std::stod(ed.get_text());  //converting string to double using stod         
}


int Mainwin::get_int(std::string prompt)
{
	EntryDialog ed{*this, prompt};
	ed.set_text("");
	ed.run();
	return std::stoi(ed.get_text());     //converting string value to int using int    
	
}
void Mainwin::set_data(std::string s)
{
	data->set_markup(s);
}
void Mainwin::set_msg(std::string s)
{
	
	msg->set_markup(s);
}


