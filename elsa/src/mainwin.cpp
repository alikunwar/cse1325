#include "mainwin.h"
#include <iostream> // for std::cerr logging
#include <string.h>
#include <sstream>
#include <fstream>

#include "entrydialog.h"

Mainwin::Mainwin() : store{nullptr}
{

  // /////////////////
  // G U I   S E T U P
  // /////////////////

  set_default_size(900, 400);
  set_title("ELSA");
  Mainwin::filename = "untitled.elsa";

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

  //         New Store
  // Append New to the File menu
  Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New ", true));
  menuitem_new->signal_activate().connect([this] { this->on_new_store_click(); });
  filemenu->append(*menuitem_new);

  //         Open
  // Append Quit to the File menu
  Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
  menuitem_open->signal_activate().connect([this] { this->on_open_click(); });
  filemenu->append(*menuitem_open);

  //         Save
  // Append Quit to the File menu
  Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
  menuitem_save->signal_activate().connect([this] { this->on_save_click(); });
  filemenu->append(*menuitem_save);

  //         Save as
  // Append Quit to the File menu
  Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_SaveAs", true));
  menuitem_save_as->signal_activate().connect([this] { this->on_save_as_click(); });
  filemenu->append(*menuitem_save_as);

  //         Quit
  // Append Quit to the File menu
  Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
  menuitem_quit->signal_activate().connect([this] { this->on_quit_click(); });
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
  menuitem_customer->signal_activate().connect([this] { this->on_view_customer_click(); });
  viewmenu->append(*menuitem_customer);

 //         P E R I P H E R A L S
    // Append Peripheral to the View menu
    Gtk::MenuItem *menuitem_view_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_view_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_view_peripheral);

  //           desktop
  // Append desktop to the View menu
  Gtk::MenuItem *menuitem_desktop = Gtk::manage(new Gtk::MenuItem("_desktop", true));
  menuitem_desktop->signal_activate().connect([this] { this->on_view_desktop_click(); });
  viewmenu->append(*menuitem_desktop);

  //           order
  // Append order to the View menu
  Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_order", true));
  menuitem_order->signal_activate().connect([this] { this->on_view_order_click(); });
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
  menuitem_Customer->signal_activate().connect([this] { this->on_insert_customer_click(); });
  insertmenu->append(*menuitem_Customer);

  //           Peripheral
  // Append Peripheral to the Insert menu
  Gtk::MenuItem *menuitem_Peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
  menuitem_Peripheral->signal_activate().connect([this] { this->on_insert_peripheral_click(); });
  Gtk::Menu *var = Gtk::manage(new Gtk::Menu());
  menuitem_Peripheral->set_submenu(*var);
  insertmenu->append(*menuitem_Peripheral);
  
  //Add more menuitems on peripheral
  //RAM

Gtk::MenuItem *menuitem_ram = Gtk::manage(new Gtk::MenuItem("_RAM", true));
menuitem_ram->signal_activate().connect([this] {this->on_ram_click();});
var->append(*menuitem_ram);

//Other
Gtk::MenuItem *menuitem_other = Gtk::manage(new Gtk::MenuItem("_Other", true));
menuitem_other->signal_activate().connect([this]{this->on_other_click();});
var->append(*menuitem_other);
  

  //           Desktop
  // Append Desktop to the Desktop menu
  Gtk::MenuItem *menuitem_Desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
  menuitem_Desktop->signal_activate().connect([this] { this->on_insert_desktop_click();});
  insertmenu->append(*menuitem_Desktop);

  //           Order
  // Append Order to the Insert menu
  Gtk::MenuItem *menuitem_Order = Gtk::manage(new Gtk::MenuItem("_Order", true));
  menuitem_Order->signal_activate().connect([this] { this->on_insert_order_click(); });
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
  menuitem_about->signal_activate().connect([this] { this->on_about_click(); });
  helpmenu->append(*menuitem_about);
  
  //           E A S T E R
    // Append Easter Egg to the Help menu
    Gtk::MenuItem *menuitem_more = Gtk::manage(new Gtk::MenuItem("_More", true));
    menuitem_more->signal_activate().connect([this] {this->on_more_egg_click();});
    helpmenu->append(*menuitem_more);

  // Data   D I S P L A Y
  // Provide a text entry box to show the remaining sticks
  data = Gtk::manage(new Gtk::Label());
  data->set_hexpand(true);
  data->set_vexpand(true);
  vbox->add(*data);
  data->set_text("Welcome to ELSA!");
  store = new Store{};

  // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
  // Provide a status bar for  messages

  msg = Gtk::manage(new Gtk::Label());
  msg->set_hexpand(true);
  
  vbox->show_all(); // make everything visible
}

Mainwin::~Mainwin() {}

// /////////////////
// C A L L B A C K S
// /////////////////

// COMBINED observer / callback




void Mainwin::on_new_store_click()
{
    delete store;
	store = new Store;
	filename = "untitled.elsa";
	set_msg("Welcome to new store");
}



void Mainwin::on_save_as_click()
{
  Gtk::FileChooserDialog dialog("Please choose a file",
                                Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
  dialog.set_transient_for(*this);

  auto filter_elsa = Gtk::FileFilter::create();
  filter_elsa->set_name("Store files");
  filter_elsa->add_pattern("*.elsa");
  dialog.add_filter(filter_elsa);

  auto filter_any = Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  dialog.set_filename("untitled.elsa");

  //Add response buttons the the dialog:
  dialog.add_button("_Cancel", 0);
  dialog.add_button("_Save", 1);

  int result = dialog.run();

  if (result == 1) 
	{
		filename = dialog.get_filename();
		on_save_click();
	}
}


void Mainwin::on_open_click()
{
 
  Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            delete store; store = nullptr;
            filename = dialog.get_filename();
            std::ifstream ifs{filename};
            store = new Store{ifs};
            if(!ifs) throw std::runtime_error{"Invalid file contents"};
            on_view_customer_click();
            set_msg("Loaded " + filename);
        } catch (std::exception& e) {
            std::string err = "Unable to open store from " + filename + " (" + e.what() + " )";
            on_new_store_click();
            set_msg("<b>ERROR:</b>: " + err);
            Gtk::MessageDialog{*this, err, false, Gtk::MESSAGE_WARNING}.run();
        }
    }
}





void Mainwin::on_save_click()
{
  std::ofstream ofs{filename};
  try
  {
            store->save(ofs);
            if(!ofs) throw std::runtime_error{"File contents bad"};
            
   } 
   catch (std::exception& e) 
   {
            
            Gtk::MessageDialog{*this, "Unable to open game"}.run();
   }
}



void Mainwin::on_quit_click()
{
  close();
}



void Mainwin::on_view_peripheral_click() { 
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    oss << "<big><b>Peripherals</b></big><tt>\n\n";
    for(int i=0; i<store->num_options(); ++i) 
        oss << i << ") " << store->option(i) << "\n";
    oss<<"</tt>";
    set_data(oss.str());
    set_msg("");
}



void Mainwin::on_view_desktop_click()
{

  std::ostringstream oss;

  std::string x = "<b> Products </b>";
  oss << x << "\n";
  set_data(oss.str());

  for (int i = 0; i < store->num_desktops(); ++i)
  {
    oss << "\n"
        << i << ") " << store->desktop(i) << "\n";
  }

  set_data(oss.str());
}



void Mainwin::on_view_order_click()
{

  std::ostringstream oss;

  std::string x = "<b> Orders </b>";
  oss << x << "\n";
  set_data(oss.str());

  for (int i = 0; i < store->num_orders(); ++i)
  {
    oss << "\n"
        << i << ") " << store->order(i) << "\n";
  }

  set_data(oss.str());
}



void Mainwin::on_view_customer_click()
{
  std::ostringstream oss;

  std::string x = "<b>Name of customer(phone number, email)</b>";
  oss << x << "\n";
  set_data(oss.str());

  for (int i = 0; i < store->num_customers(); ++i)
  {
    oss << "\n"
        << i << ") " << store->customer(i);
  }
  set_data(oss.str());
}



void Mainwin::on_insert_customer_click()
{
   Gtk::Dialog dialog{"Customer", *this};

    Gtk::Grid grid;
  
    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;               // Accept any line of text
    grid.attach(l_name, 0, 1, 1, 1);
    grid.attach(e_name, 1, 1, 2, 1);
	
	Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;               // Accept any line of text
    grid.attach(l_phone, 0, 2, 1, 1);
    grid.attach(e_phone, 1, 2, 2, 1);
	dialog.get_content_area()->add(grid);
 
    Gtk::Label l_email{"Email"};
    Gtk::Entry e_email;               // Accept any line of text
    grid.attach(l_email, 0, 3, 1, 1);
    grid.attach(e_email, 1, 3, 2, 1);
	dialog.get_content_area()->add(grid);
   
    dialog.add_button("Select", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
    // NOTE: The x in the title bar to close the dialog is Gtk::RESPONSE_DELETE_EVENT
    int response;

    // It's ready!  Now display it to the user.
    dialog.show_all();

    while((response = dialog.run()) == Gtk::RESPONSE_OK) {

        // Data validation: If the user doesn't enter a name for the animal, complain
        if (e_name.get_text().size() == 0) {e_name.set_text("*REQUIRED*"); continue;}
        if (e_phone.get_text().size() == 0) {e_phone.set_text("*REQUIRED*"); continue;}
		if (e_email.get_text().size() == 0) {e_email.set_text("*REQUIRED*"); continue;}
        // Otherwise, extract the information entered into the various widgets
        std::string name = e_name.get_text(); 
		std::string phone = e_phone.get_text();
        std::string email= e_email.get_text();
		Customer customer{name,phone,email};
		store->add_customer(customer);
		Gtk::MessageDialog{*this, "You selected a " + name + " ( " + phone + " " + email + " )"}.run();
		break;

       
    }
	 msg->set_text("New Customer Added!");
}


void Mainwin::on_insert_peripheral_click()
{

}
void Mainwin::on_ram_click()
{
EntryDialog ed1{*this, "Name of the partb you want to buy"};
ed1.set_text("Name");
ed1.run();
std::string name = ed1.get_text();


EntryDialog ed2{*this, "Cost of the product($)" };
ed2.run();
std::string price = ed2.get_text();

double pr;
pr = std::stod(price);

EntryDialog ed3{*this, "Enter memory of RAM" };
ed3.run();
std::string gb = ed3.get_text();
int x= std::stoi(gb);
 
try 
{

} 
catch(std::exception& e) 
{
std::cerr << "#### INVALID OPTION ####\n\n";
}

msg->set_text("Ram Added!");
}



void Mainwin::on_other_click()
{
EntryDialog ed1{*this, "Please select the part"};
ed1.set_text("name");
ed1.run();

std::string name = ed1.get_text();
EntryDialog ed2{*this, "Cost of the part" };
ed2.run();
std::string newprice = ed2.get_text();
double price = std::stod(newprice);

Options *y = new Options(name,price);
try
 {
} 
catch(std::exception& e) 
{
std::cerr << "#### INVALID OPTION ####\n\n";
}
}




void Mainwin::on_insert_order_click()
{
  on_view_customer_click();
  std::ostringstream oss;

  int customer = get_int("Number of line of the customer");

  int order = store->new_order(customer);
  on_view_desktop_click();
  while (true)
  {

    int desktop = get_int("Which Desktop? (-1 to exit)");

    if (desktop == -1)
      break;
    store->add_desktop(desktop, order);
  }

  //on_view_order_click();
  oss << "\n++++ Order Placed ++++\n"
      << store->order(order);
}



void Mainwin::on_insert_desktop_click()
{
  int desktop = store->new_desktop();
  std::ostringstream oss;

  while (true)
  {
    oss << "\n"
        << store->desktop(desktop) << "\n\n";

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

void Mainwin::on_more_egg_click() {
    Customer c{"Alisha", "469-234-4564", "bugs@loony.tunes"};          store->add_customer(c);
    c = Customer{"Rajiv", "682-607-4567", "helen@incredibles.movie"}; store->add_customer(c);
    c = Customer{"Nischal", "469-009-6547", "circus@bugs.life"};     store->add_customer(c);
    

    Options o{"CPU: 2.6 GHz Xeon 6126T", 2423.47};         store->add_option(o);
    o = Options{"CPU: 2.4 GHz Core i7-8565U", 388.0};      store->add_option(o);
    o = Options{"CPU: 2.2 GHz AMD Opteron", 37.71};        store->add_option(o);
    o = Options{"2 GB RAM", 17.76};                        store->add_option(o);
    o = Options{"4 GB RAM", 22.95};                        store->add_option(o);
    o = Options{"8 GB RAM", 34.99};                        store->add_option(o);
}


double Mainwin::get_double(std::string prompt)
{
  EntryDialog ed{*this, prompt};
  ed.set_text("");
  ed.run();
  return std::stod(ed.get_text()); //converting string to double using stod
}



int Mainwin::get_int(std::string prompt)
{
  EntryDialog ed{*this, prompt};
  ed.set_text("");
  ed.run();
  return std::stoi(ed.get_text()); //converting string value to int using int
}


void Mainwin::set_data(std::string s)
{
  data->set_markup(s);
}


void Mainwin::set_msg(std::string s)
{
  msg->set_markup(s);
}
