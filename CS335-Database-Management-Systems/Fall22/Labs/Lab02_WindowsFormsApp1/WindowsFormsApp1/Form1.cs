using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Assignment1 : Form
    {
        public string stdisbn { get; set; }
        public string stdtitlebox { get; set; }
        public int stdcatindex { get; set; }
        public int stdsubcatindex { get; set; }
        public string stdauthors { get; set; }
        public DateTime stdpurchasedon { get; set; }
        public int stdtype { get; set; }
        public bool stdisIssued { get; set; }
        public string stdissuedTo { get; set; }
        public DateTime stdissuedOn { get; set; }

        public Assignment1()
        {
            InitializeComponent();
            this.comboBox1.Items.AddRange(new object[] {
            "Database Systems",
            "OOP",
            "Artificial Intelligence"});


        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click_1(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (this.comboBox1.SelectedItem.ToString() == "Database Systems")
            {
                this.comboBox2.Items.Clear();
                this.comboBox2.Items.Add("ERD");
                this.comboBox2.Items.Add("SQL");
                this.comboBox2.Items.Add("OLAP");
                this.comboBox2.Items.Add("Data Mining");
            }
            else if (this.comboBox1.SelectedItem.ToString() == "OOP")
            {
                this.comboBox2.Items.Clear();
                this.comboBox2.Items.Add("C++");
                this.comboBox2.Items.Add("Java");
            }
            else if (this.comboBox1.SelectedItem.ToString() == "Artificial Intelligence")
            {
                this.comboBox2.Items.Clear();
                this.comboBox2.Items.Add("Machine Learning");
                this.comboBox2.Items.Add("Robotics");
                this.comboBox2.Items.Add("Computer Vision");
            }

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.author.Text != "")
            {
                this.authorbox.Items.Add(this.author.Text);
                this.author.Clear();
            }
        }

        private void Assignment1_Load(object sender, EventArgs e)
        {
            isbnbox.Text = stdisbn;
            titlebox.Text = stdtitlebox;
            purchasedate.Value = stdpurchasedon;
            comboBox1.SelectedIndex = stdcatindex - 1;
            comboBox2.SelectedIndex = stdsubcatindex - 1;
            issuedto.Text = stdissuedTo;
            issuedate.Value = stdissuedOn;

            if (stdtype == 1)
            {
                refbook.Checked = true;
            }
            else if (stdtype == 2)
            {
                textbook.Checked = true;
            }
            else if (stdtype == 3)
            {
                journal.Checked = true;
            }
            
            if (stdisIssued == true)
            {
                issue_check.Checked = true;
            }

            string[] people = stdauthors.Split(';');
            foreach(string p in people)
            {
                authorbox.Items.Add(p);
            }

        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void issue_check_CheckedChanged(object sender, EventArgs e)
        {
            if (this.issue_check.Checked == true)
            {
                this.issuedto.Enabled = false;
                this.issuedate.Enabled = false;
            }
            else if (this.issue_check.Checked == false)
            {
                this.issuedto.Enabled = true;
                this.issuedate.Enabled = true;
            }
        }

        private void ok_Click(object sender, EventArgs e)
        {
            var error = false;
            if (this.isbnbox.TextLength > 12 || DateTime.Compare(purchasedate.Value, DateTime.Today) > 0)
            {
                MessageBox.Show("The Length of ISBN is greater than 12 or Purchased On Date is greater than today", "Confirmation", MessageBoxButtons.OK); error = true;
            }
            if (this.journal.Checked == true)
            {
                if (authorbox.Items.Count != 0)
                {
                    MessageBox.Show("Book of Jounral Type shuold have no authors.", "Confirmation", MessageBoxButtons.OK); error = true;
                }
            }
            if (this.refbook.Checked == true || this.textbook.Checked == true)
            {
                if (authorbox.Items.Count == 0)
                {
                    MessageBox.Show("Reference and Textbook should have at least one author", "Confirmation", MessageBoxButtons.OK); error = true;
                }
            }
            if (issue_check.Checked == true)
            {
                if (issuedto.Text.Length == 0)
                {
                    MessageBox.Show("The 'Issued to' field is empty", "Confirmation", MessageBoxButtons.OK); error = true;
                }
                if (DateTime.Compare(issuedate.Value, purchasedate.Value) < 0)
                {
                    MessageBox.Show("The Issue date is earlier than the Purchased on Date", "Confirmation", MessageBoxButtons.OK); error = true;
                }
            }
            if (error == false)
            {
                MessageBox.Show("Book added Successfully!", "Confirmation", MessageBoxButtons.OK);
            }
        }   

        private void close_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void issuedate_ValueChanged(object sender, EventArgs e)
        {

        }
    }
}
