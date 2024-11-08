namespace WindowsFormsApp1
{
    partial class Assignment1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.ISBN = new System.Windows.Forms.Label();
            this.Title = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.isbnbox = new System.Windows.Forms.TextBox();
            this.titlebox = new System.Windows.Forms.TextBox();
            this.purchasedate = new System.Windows.Forms.DateTimePicker();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.Authors = new System.Windows.Forms.GroupBox();
            this.authorbox = new System.Windows.Forms.ListBox();
            this.button1 = new System.Windows.Forms.Button();
            this.author = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.journal = new System.Windows.Forms.RadioButton();
            this.textbook = new System.Windows.Forms.RadioButton();
            this.refbook = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.issuedate = new System.Windows.Forms.DateTimePicker();
            this.label6 = new System.Windows.Forms.Label();
            this.issuedto = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.issue_check = new System.Windows.Forms.CheckBox();
            this.ok = new System.Windows.Forms.Button();
            this.close = new System.Windows.Forms.Button();
            this.Authors.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // ISBN
            // 
            this.ISBN.AutoSize = true;
            this.ISBN.Location = new System.Drawing.Point(103, 41);
            this.ISBN.Name = "ISBN";
            this.ISBN.Size = new System.Drawing.Size(44, 20);
            this.ISBN.TabIndex = 0;
            this.ISBN.Text = "ISBN:";
            this.ISBN.Click += new System.EventHandler(this.label1_Click);
            // 
            // Title
            // 
            this.Title.AutoSize = true;
            this.Title.Location = new System.Drawing.Point(103, 87);
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(41, 20);
            this.Title.TabIndex = 1;
            this.Title.Text = "Title:";
            this.Title.Click += new System.EventHandler(this.label2_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(103, 135);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(102, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Purchased On:";
            this.label1.Click += new System.EventHandler(this.label1_Click_1);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(103, 180);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(72, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Category:";
            this.label2.Click += new System.EventHandler(this.label2_Click_1);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(103, 231);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(101, 20);
            this.label3.TabIndex = 4;
            this.label3.Text = "Sub Category:";
            // 
            // isbnbox
            // 
            this.isbnbox.Location = new System.Drawing.Point(274, 31);
            this.isbnbox.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.isbnbox.Name = "isbnbox";
            this.isbnbox.Size = new System.Drawing.Size(135, 27);
            this.isbnbox.TabIndex = 5;
            // 
            // titlebox
            // 
            this.titlebox.Location = new System.Drawing.Point(274, 76);
            this.titlebox.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.titlebox.Name = "titlebox";
            this.titlebox.Size = new System.Drawing.Size(268, 27);
            this.titlebox.TabIndex = 6;
            // 
            // purchasedate
            // 
            this.purchasedate.AllowDrop = true;
            this.purchasedate.Location = new System.Drawing.Point(274, 124);
            this.purchasedate.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.purchasedate.Name = "purchasedate";
            this.purchasedate.Size = new System.Drawing.Size(268, 27);
            this.purchasedate.TabIndex = 7;
            // 
            // comboBox1
            // 
            this.comboBox1.AllowDrop = true;
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(272, 169);
            this.comboBox1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(270, 28);
            this.comboBox1.TabIndex = 8;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // comboBox2
            // 
            this.comboBox2.AllowDrop = true;
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Location = new System.Drawing.Point(272, 220);
            this.comboBox2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(270, 28);
            this.comboBox2.TabIndex = 8;
            this.comboBox2.SelectedIndexChanged += new System.EventHandler(this.comboBox2_SelectedIndexChanged);
            // 
            // Authors
            // 
            this.Authors.Controls.Add(this.authorbox);
            this.Authors.Controls.Add(this.button1);
            this.Authors.Controls.Add(this.author);
            this.Authors.Controls.Add(this.label4);
            this.Authors.Location = new System.Drawing.Point(103, 280);
            this.Authors.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Authors.Name = "Authors";
            this.Authors.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Authors.Size = new System.Drawing.Size(440, 287);
            this.Authors.TabIndex = 9;
            this.Authors.TabStop = false;
            this.Authors.Text = "Authors";
            this.Authors.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // authorbox
            // 
            this.authorbox.FormattingEnabled = true;
            this.authorbox.ItemHeight = 20;
            this.authorbox.Location = new System.Drawing.Point(169, 81);
            this.authorbox.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.authorbox.Name = "authorbox";
            this.authorbox.Size = new System.Drawing.Size(155, 164);
            this.authorbox.TabIndex = 12;
            this.authorbox.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(347, 24);
            this.button1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(86, 31);
            this.button1.TabIndex = 3;
            this.button1.Text = "Add";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // author
            // 
            this.author.Location = new System.Drawing.Point(169, 24);
            this.author.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.author.Name = "author";
            this.author.Size = new System.Drawing.Size(155, 27);
            this.author.TabIndex = 1;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(7, 37);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(101, 20);
            this.label4.TabIndex = 0;
            this.label4.Text = "Author Name:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.journal);
            this.groupBox1.Controls.Add(this.textbook);
            this.groupBox1.Controls.Add(this.refbook);
            this.groupBox1.Location = new System.Drawing.Point(103, 587);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox1.Size = new System.Drawing.Size(171, 193);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Type";
            // 
            // journal
            // 
            this.journal.AutoSize = true;
            this.journal.Location = new System.Drawing.Point(27, 96);
            this.journal.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.journal.Name = "journal";
            this.journal.Size = new System.Drawing.Size(77, 24);
            this.journal.TabIndex = 2;
            this.journal.TabStop = true;
            this.journal.Text = "Journal";
            this.journal.UseVisualStyleBackColor = true;
            this.journal.CheckedChanged += new System.EventHandler(this.radioButton3_CheckedChanged);
            // 
            // textbook
            // 
            this.textbook.AutoSize = true;
            this.textbook.Location = new System.Drawing.Point(27, 63);
            this.textbook.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.textbook.Name = "textbook";
            this.textbook.Size = new System.Drawing.Size(95, 24);
            this.textbook.TabIndex = 1;
            this.textbook.TabStop = true;
            this.textbook.Text = "Text Book";
            this.textbook.UseVisualStyleBackColor = true;
            // 
            // refbook
            // 
            this.refbook.AutoSize = true;
            this.refbook.Location = new System.Drawing.Point(27, 29);
            this.refbook.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.refbook.Name = "refbook";
            this.refbook.Size = new System.Drawing.Size(134, 24);
            this.refbook.TabIndex = 0;
            this.refbook.TabStop = true;
            this.refbook.Text = "Reference Book";
            this.refbook.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.issuedate);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.issuedto);
            this.groupBox2.Controls.Add(this.label5);
            this.groupBox2.Controls.Add(this.issue_check);
            this.groupBox2.Location = new System.Drawing.Point(282, 587);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox2.Size = new System.Drawing.Size(261, 193);
            this.groupBox2.TabIndex = 11;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Issuance";
            // 
            // issuedate
            // 
            this.issuedate.Location = new System.Drawing.Point(113, 127);
            this.issuedate.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.issuedate.Name = "issuedate";
            this.issuedate.Size = new System.Drawing.Size(134, 27);
            this.issuedate.TabIndex = 4;
            this.issuedate.ValueChanged += new System.EventHandler(this.issuedate_ValueChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(18, 132);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(89, 20);
            this.label6.TabIndex = 3;
            this.label6.Text = "Issued Date:";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // issuedto
            // 
            this.issuedto.Location = new System.Drawing.Point(113, 80);
            this.issuedto.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.issuedto.Name = "issuedto";
            this.issuedto.Size = new System.Drawing.Size(134, 27);
            this.issuedto.TabIndex = 2;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(18, 83);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(71, 20);
            this.label5.TabIndex = 1;
            this.label5.Text = "Issued to:";
            // 
            // issue_check
            // 
            this.issue_check.AutoSize = true;
            this.issue_check.Location = new System.Drawing.Point(18, 31);
            this.issue_check.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.issue_check.Name = "issue_check";
            this.issue_check.Size = new System.Drawing.Size(72, 24);
            this.issue_check.TabIndex = 0;
            this.issue_check.Text = "Issued";
            this.issue_check.UseVisualStyleBackColor = true;
            this.issue_check.CheckedChanged += new System.EventHandler(this.issue_check_CheckedChanged);
            // 
            // ok
            // 
            this.ok.Location = new System.Drawing.Point(422, 845);
            this.ok.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.ok.Name = "ok";
            this.ok.Size = new System.Drawing.Size(86, 31);
            this.ok.TabIndex = 12;
            this.ok.Text = "OK";
            this.ok.UseVisualStyleBackColor = true;
            this.ok.Click += new System.EventHandler(this.ok_Click);
            // 
            // close
            // 
            this.close.Location = new System.Drawing.Point(514, 845);
            this.close.Name = "close";
            this.close.Size = new System.Drawing.Size(88, 31);
            this.close.TabIndex = 13;
            this.close.Text = "Close";
            this.close.UseVisualStyleBackColor = true;
            this.close.Click += new System.EventHandler(this.close_Click);
            // 
            // Assignment1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(614, 1005);
            this.Controls.Add(this.close);
            this.Controls.Add(this.ok);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.Authors);
            this.Controls.Add(this.comboBox2);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.purchasedate);
            this.Controls.Add(this.titlebox);
            this.Controls.Add(this.isbnbox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Title);
            this.Controls.Add(this.ISBN);
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Assignment1";
            this.Text = "Assignment1";
            this.Load += new System.EventHandler(this.Assignment1_Load);
            this.Authors.ResumeLayout(false);
            this.Authors.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label ISBN;
        private System.Windows.Forms.Label Title;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox isbnbox;
        private System.Windows.Forms.TextBox titlebox;
        private System.Windows.Forms.DateTimePicker purchasedate;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.GroupBox Authors;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox author;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton journal;
        private System.Windows.Forms.RadioButton textbook;
        private System.Windows.Forms.RadioButton refbook;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox issuedto;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.CheckBox issue_check;
        private System.Windows.Forms.DateTimePicker issuedate;
        private System.Windows.Forms.ListBox authorbox;
        private System.Windows.Forms.Button ok;
        private System.Windows.Forms.Button close;
    }
}

