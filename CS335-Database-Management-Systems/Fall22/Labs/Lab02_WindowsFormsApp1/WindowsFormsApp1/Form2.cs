using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace WindowsFormsApp1
{
    public partial class BookSearch : Form
    {
        public BookSearch()
        {
            InitializeComponent();

            this.catbox.Items.AddRange(new object[] {
            "Database Systems",
            "OOP",
            "Artificial Intelligence"});
            
            List<Book> books = new List<Book>();

            // Code to be copied in the Form2 Constructor
            books.Add(new Book("0201144719 9780201144710", "An introduction to database systems", 1, 1, "C J Date", Convert.ToDateTime("1 jan 2015"), 1, false, "", Convert.ToDateTime("30 Nov 2015"))); books.Add(new Book("0805301453 9780805301458", "Fundamentals of database systems", 1, 1, "Ramez Elmasri; Sham Navathe", Convert.ToDateTime("10 jan 2015"), 2, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("1571690867 9781571690869", "Object oriented programming in Java", 2, 2, "Stephen Gilbert; Bill McCarty", Convert.ToDateTime("15 jan 2015"), 1, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("1842652478 9781842652473", "Object oriented programming using C++", 2, 1, "B Chandra", Convert.ToDateTime("16 jan 2015"), 2, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("0070522618 9780070522619", "Artificial intelligence", 3, 2, "Elaine Rich", Convert.ToDateTime("20 jan 2015"), 1, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("0865760047 9780865760042", "The Handbook of artificial intelligence", 3, 2, "Avron Barr; Edward A Feigenbaum; Paul R Cohen", Convert.ToDateTime("22 jan 2015"), 2, false, "", Convert.ToDateTime("30 Nov 2015")));
            foreach (Book b in books)
            {

                if (b.catIndex == 0)
                {
                    result_lstbox.Items.Add(b.ISBN + "/" + "(Select)" + "/" + b.Title);
                }
                else if (b.catIndex == 1)
                {
                    result_lstbox.Items.Add(b.ISBN + "/" + "Database Systems" + "/" + b.Title);
                }
                else if (b.catIndex == 2)
                {
                    result_lstbox.Items.Add(b.ISBN + "/" + "OOP" + "/" + b.Title);
                }
                else
                {
                    result_lstbox.Items.Add(b.ISBN + "/" + "Artificial Intelligence " + "/" + b.Title);
                }
            }
        }

        public class Book
        {
            public string ISBN;
            public string Title;
            public int catIndex;
            public int subcatIndex;
            public string authors;
            public DateTime purchasedon;
            public int type;
            public bool isIssued;
            public string issuedTo;
            public DateTime issuedOn;

            public Book(string _ISBN, string _title, int _cat, int _subcat, string _authors, DateTime _purchasedOn, int _type, bool _isIssued, string _issuedTo, DateTime _issuedDate)
            {
                ISBN = _ISBN;
                Title = _title;
                catIndex = _cat;
                subcatIndex = _subcat;
                authors = _authors;
                purchasedon = _purchasedOn;
                type = _type;
                isIssued = _isIssued;
                issuedTo = _issuedTo;
                issuedOn = _issuedDate;

            }
        }
        private void BookSearch_Load(object sender, EventArgs e)
        {

        }

        private void category_lbl_Click(object sender, EventArgs e)
        {

        }

        private void title_lbl_Click(object sender, EventArgs e)
        {

        }

        private void catbox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void close_button_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void view_button_Click(object sender, EventArgs e)
        {

            List<Book> books = new List<Book>();

            // Code to be copied in the Form2 Constructor
            books.Add(new Book("0201144719 9780201144710", "An introduction to database systems", 1, 1, "C J Date", Convert.ToDateTime("1 jan 2015"), 1, false, "", Convert.ToDateTime("30 Nov 2015"))); books.Add(new Book("0805301453 9780805301458", "Fundamentals of database systems", 1, 1, "Ramez Elmasri; Sham Navathe", Convert.ToDateTime("10 jan 2015"), 2, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("1571690867 9781571690869", "Object oriented programming in Java", 2, 2, "Stephen Gilbert; Bill McCarty", Convert.ToDateTime("15 jan 2015"), 1, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("1842652478 9781842652473", "Object oriented programming using C++", 2, 1, "B Chandra", Convert.ToDateTime("16 jan 2015"), 2, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("0070522618 9780070522619", "Artificial intelligence", 3, 2, "Elaine Rich", Convert.ToDateTime("20 jan 2015"), 1, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("0865760047 9780865760042", "The Handbook of artificial intelligence", 3, 2, "Avron Barr; Edward A Feigenbaum; Paul R Cohen", Convert.ToDateTime("22 jan 2015"), 2, false, "", Convert.ToDateTime("30 Nov 2015")));


            Assignment1 view = new Assignment1();

            string sent = result_lstbox.SelectedItem.ToString();
            string[] w = sent.Split('/');

            foreach (Book b in books)
            {
                if (b.ISBN == w[0])
                {
                    view.stdisbn = w[0];
                    view.stdtitlebox = w[2];
                    view.stdcatindex = b.catIndex;
                    view.stdsubcatindex = b.subcatIndex;
                    view.stdauthors = b.authors;
                    view.stdpurchasedon = b.purchasedon;
                    view.stdtype = b.type;
                    view.stdisIssued = b.isIssued;
                    view.stdissuedOn = b.issuedOn;
                    view.stdissuedTo = b.issuedTo;
                }
            }

            view.ShowDialog();
        }

        private void delete_button_Click(object sender, EventArgs e)
        {
            DialogResult = MessageBox.Show("Do you really want to delete this book?", "Confirm", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (DialogResult == DialogResult.Yes)
            {
                result_lstbox.Items.Remove(result_lstbox.SelectedItem);
            }
        }

        private void result_lstbox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void search_button_Click(object sender, EventArgs e)
        {
            List<Book> books = new List<Book>();

            // Code to be copied in the Form2 Constructor
            books.Add(new Book("0201144719 9780201144710", "An introduction to database systems", 1, 1, "C J Date", Convert.ToDateTime("1 jan 2015"), 1, false, "", Convert.ToDateTime("30 Nov 2015"))); books.Add(new Book("0805301453 9780805301458", "Fundamentals of database systems", 1, 1, "Ramez Elmasri; Sham Navathe", Convert.ToDateTime("10 jan 2015"), 2, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("1571690867 9781571690869", "Object oriented programming in Java", 2, 2, "Stephen Gilbert; Bill McCarty", Convert.ToDateTime("15 jan 2015"), 1, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("1842652478 9781842652473", "Object oriented programming using C++", 2, 1, "B Chandra", Convert.ToDateTime("16 jan 2015"), 2, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("0070522618 9780070522619", "Artificial intelligence", 3, 2, "Elaine Rich", Convert.ToDateTime("20 jan 2015"), 1, false, "", Convert.ToDateTime("30 Nov 2015")));
            books.Add(new Book("0865760047 9780865760042", "The Handbook of artificial intelligence", 3, 2, "Avron Barr; Edward A Feigenbaum; Paul R Cohen", Convert.ToDateTime("22 jan 2015"), 2, false, "", Convert.ToDateTime("30 Nov 2015")));




            result_lstbox.Items.Clear();
            List<Book> categ = new List<Book>();
            List<Book> name = new List<Book>();
            List<Book> issued = new List<Book>();
            List<Book> t = new List<Book>();

            foreach (Book book in books)
            {
                if (catbox.SelectedItem != null)
                {

                    if (catbox.SelectedIndex == book.catIndex - 1)
                    {
                        categ.Add(book);
                    }
                }
                else
                {
                    categ.Add(book);
                }

                if (titlebox.Text != "")
                {
                    if (book.Title.StartsWith(titlebox.Text, StringComparison.CurrentCultureIgnoreCase))
                    {
                        name.Add(book);
                    }
                }
                else
                {
                    name.Add(book);
                }

                if (issuedcheck.Checked)
                {
                    if (book.isIssued == true)
                    {
                        issued.Add(book);
                    }
                }
                else
                {
                    issued.Add(book);
                }

                if (refbook.Checked)
                {
                    if (book.type == 1)
                    {
                        t.Add(book);
                    }
                }
                else if (txtbook.Checked)
                {
                    if (book.type == 2)
                    {
                        t.Add(book);
                    }
                }
                else if (journal.Checked)
                {
                    if (book.type == 3)
                    {
                        t.Add(book);
                    }
                }
                else
                {
                    t.Add(book);
                }
            }

            List<Book> filtered = new List<Book>();

            //Showing the filtered results in the listbox
            foreach (Book book in books)
            {
                if (categ.Contains(book) & name.Contains(book) & issued.Contains(book) & t.Contains(book))
                {
                    filtered.Add(book);
                    if (book.catIndex == 1)
                    {
                        result_lstbox.Items.Add(book.ISBN + "/" + "Database Systems" + "/" +
                        book.Title);
                    }
                    else if (book.catIndex == 2)
                    {
                        result_lstbox.Items.Add(book.ISBN + "/" + "OOP" + "/" + book.Title);
                    }
                    else
                    {
                        result_lstbox.Items.Add(book.ISBN + "/" + "Artificial Intelligence" + "/" +
                        book.Title);
                    }

                }
            }
        }
    }
}
