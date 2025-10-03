namespace WindowsFormsApp1
{
    partial class BookSearch
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.searchbox = new System.Windows.Forms.GroupBox();
            this.search_button = new System.Windows.Forms.Button();
            this.typebox = new System.Windows.Forms.GroupBox();
            this.journal = new System.Windows.Forms.RadioButton();
            this.txtbook = new System.Windows.Forms.RadioButton();
            this.refbook = new System.Windows.Forms.RadioButton();
            this.issuedcheck = new System.Windows.Forms.CheckBox();
            this.titlebox = new System.Windows.Forms.TextBox();
            this.title_lbl = new System.Windows.Forms.Label();
            this.catbox = new System.Windows.Forms.ComboBox();
            this.category_lbl = new System.Windows.Forms.Label();
            this.resultbox = new System.Windows.Forms.GroupBox();
            this.result_lstbox = new System.Windows.Forms.ListBox();
            this.view_button = new System.Windows.Forms.Button();
            this.delete_button = new System.Windows.Forms.Button();
            this.close_button = new System.Windows.Forms.Button();
            this.searchbox.SuspendLayout();
            this.typebox.SuspendLayout();
            this.resultbox.SuspendLayout();
            this.SuspendLayout();
            // 
            // searchbox
            // 
            this.searchbox.Controls.Add(this.search_button);
            this.searchbox.Controls.Add(this.typebox);
            this.searchbox.Controls.Add(this.issuedcheck);
            this.searchbox.Controls.Add(this.titlebox);
            this.searchbox.Controls.Add(this.title_lbl);
            this.searchbox.Controls.Add(this.catbox);
            this.searchbox.Controls.Add(this.category_lbl);
            this.searchbox.Location = new System.Drawing.Point(12, 12);
            this.searchbox.Name = "searchbox";
            this.searchbox.Size = new System.Drawing.Size(649, 210);
            this.searchbox.TabIndex = 0;
            this.searchbox.TabStop = false;
            this.searchbox.Text = "Search";
            // 
            // search_button
            // 
            this.search_button.Location = new System.Drawing.Point(534, 165);
            this.search_button.Name = "search_button";
            this.search_button.Size = new System.Drawing.Size(94, 29);
            this.search_button.TabIndex = 6;
            this.search_button.Text = "Search";
            this.search_button.UseVisualStyleBackColor = true;
            this.search_button.Click += new System.EventHandler(this.search_button_Click);
            // 
            // typebox
            // 
            this.typebox.Controls.Add(this.journal);
            this.typebox.Controls.Add(this.txtbook);
            this.typebox.Controls.Add(this.refbook);
            this.typebox.Location = new System.Drawing.Point(400, 25);
            this.typebox.Name = "typebox";
            this.typebox.Size = new System.Drawing.Size(228, 125);
            this.typebox.TabIndex = 5;
            this.typebox.TabStop = false;
            this.typebox.Text = "Type";
            // 
            // journal
            // 
            this.journal.AutoSize = true;
            this.journal.Location = new System.Drawing.Point(21, 86);
            this.journal.Name = "journal";
            this.journal.Size = new System.Drawing.Size(77, 24);
            this.journal.TabIndex = 2;
            this.journal.TabStop = true;
            this.journal.Text = "Journal";
            this.journal.UseVisualStyleBackColor = true;
            // 
            // txtbook
            // 
            this.txtbook.AutoSize = true;
            this.txtbook.Location = new System.Drawing.Point(21, 56);
            this.txtbook.Name = "txtbook";
            this.txtbook.Size = new System.Drawing.Size(95, 24);
            this.txtbook.TabIndex = 1;
            this.txtbook.TabStop = true;
            this.txtbook.Text = "Text Book";
            this.txtbook.UseVisualStyleBackColor = true;
            // 
            // refbook
            // 
            this.refbook.AutoSize = true;
            this.refbook.Location = new System.Drawing.Point(21, 26);
            this.refbook.Name = "refbook";
            this.refbook.Size = new System.Drawing.Size(134, 24);
            this.refbook.TabIndex = 0;
            this.refbook.TabStop = true;
            this.refbook.Text = "Reference Book";
            this.refbook.UseVisualStyleBackColor = true;
            // 
            // issuedcheck
            // 
            this.issuedcheck.AutoSize = true;
            this.issuedcheck.Location = new System.Drawing.Point(88, 126);
            this.issuedcheck.Name = "issuedcheck";
            this.issuedcheck.Size = new System.Drawing.Size(72, 24);
            this.issuedcheck.TabIndex = 4;
            this.issuedcheck.Text = "Issued";
            this.issuedcheck.UseVisualStyleBackColor = true;
            // 
            // titlebox
            // 
            this.titlebox.Location = new System.Drawing.Point(88, 80);
            this.titlebox.Name = "titlebox";
            this.titlebox.Size = new System.Drawing.Size(272, 27);
            this.titlebox.TabIndex = 3;
            // 
            // title_lbl
            // 
            this.title_lbl.AutoSize = true;
            this.title_lbl.Location = new System.Drawing.Point(6, 83);
            this.title_lbl.Name = "title_lbl";
            this.title_lbl.Size = new System.Drawing.Size(45, 20);
            this.title_lbl.TabIndex = 2;
            this.title_lbl.Text = "Title :";
            this.title_lbl.Click += new System.EventHandler(this.title_lbl_Click);
            // 
            // catbox
            // 
            this.catbox.FormattingEnabled = true;
            this.catbox.Location = new System.Drawing.Point(88, 31);
            this.catbox.Name = "catbox";
            this.catbox.Size = new System.Drawing.Size(151, 28);
            this.catbox.TabIndex = 1;
            this.catbox.SelectedIndexChanged += new System.EventHandler(this.catbox_SelectedIndexChanged);
            // 
            // category_lbl
            // 
            this.category_lbl.AutoSize = true;
            this.category_lbl.Location = new System.Drawing.Point(6, 34);
            this.category_lbl.Name = "category_lbl";
            this.category_lbl.Size = new System.Drawing.Size(76, 20);
            this.category_lbl.TabIndex = 0;
            this.category_lbl.Text = "Category: ";
            this.category_lbl.Click += new System.EventHandler(this.category_lbl_Click);
            // 
            // resultbox
            // 
            this.resultbox.Controls.Add(this.result_lstbox);
            this.resultbox.Location = new System.Drawing.Point(12, 242);
            this.resultbox.Name = "resultbox";
            this.resultbox.Size = new System.Drawing.Size(649, 301);
            this.resultbox.TabIndex = 1;
            this.resultbox.TabStop = false;
            this.resultbox.Text = "Result";
            // 
            // result_lstbox
            // 
            this.result_lstbox.FormattingEnabled = true;
            this.result_lstbox.ItemHeight = 20;
            this.result_lstbox.Location = new System.Drawing.Point(15, 31);
            this.result_lstbox.Name = "result_lstbox";
            this.result_lstbox.Size = new System.Drawing.Size(628, 264);
            this.result_lstbox.TabIndex = 0;
            this.result_lstbox.SelectedIndexChanged += new System.EventHandler(this.result_lstbox_SelectedIndexChanged);
            // 
            // view_button
            // 
            this.view_button.Location = new System.Drawing.Point(462, 564);
            this.view_button.Name = "view_button";
            this.view_button.Size = new System.Drawing.Size(94, 29);
            this.view_button.TabIndex = 2;
            this.view_button.Text = "View";
            this.view_button.UseVisualStyleBackColor = true;
            this.view_button.Click += new System.EventHandler(this.view_button_Click);
            // 
            // delete_button
            // 
            this.delete_button.Location = new System.Drawing.Point(562, 564);
            this.delete_button.Name = "delete_button";
            this.delete_button.Size = new System.Drawing.Size(94, 29);
            this.delete_button.TabIndex = 3;
            this.delete_button.Text = "Delete";
            this.delete_button.UseVisualStyleBackColor = true;
            this.delete_button.Click += new System.EventHandler(this.delete_button_Click);
            // 
            // close_button
            // 
            this.close_button.Location = new System.Drawing.Point(562, 599);
            this.close_button.Name = "close_button";
            this.close_button.Size = new System.Drawing.Size(94, 29);
            this.close_button.TabIndex = 4;
            this.close_button.Text = "Close";
            this.close_button.UseVisualStyleBackColor = true;
            this.close_button.Click += new System.EventHandler(this.close_button_Click);
            // 
            // BookSearch
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(673, 639);
            this.Controls.Add(this.close_button);
            this.Controls.Add(this.delete_button);
            this.Controls.Add(this.view_button);
            this.Controls.Add(this.resultbox);
            this.Controls.Add(this.searchbox);
            this.Name = "BookSearch";
            this.Text = "Book Search";
            this.Load += new System.EventHandler(this.BookSearch_Load);
            this.searchbox.ResumeLayout(false);
            this.searchbox.PerformLayout();
            this.typebox.ResumeLayout(false);
            this.typebox.PerformLayout();
            this.resultbox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox searchbox;
        private System.Windows.Forms.CheckBox issuedcheck;
        private System.Windows.Forms.TextBox titlebox;
        private System.Windows.Forms.Label title_lbl;
        private System.Windows.Forms.ComboBox catbox;
        private System.Windows.Forms.Label category_lbl;
        private System.Windows.Forms.Button search_button;
        private System.Windows.Forms.GroupBox typebox;
        private System.Windows.Forms.RadioButton journal;
        private System.Windows.Forms.RadioButton txtbook;
        private System.Windows.Forms.RadioButton refbook;
        private System.Windows.Forms.GroupBox resultbox;
        private System.Windows.Forms.Button view_button;
        private System.Windows.Forms.Button delete_button;
        private System.Windows.Forms.Button close_button;
        private System.Windows.Forms.ListBox result_lstbox;
    }
}