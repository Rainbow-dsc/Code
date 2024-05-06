private void btnCatchMe_Click(object sender, EventArgs e); 

{

MessageBox.Show("抓到我了，算你聪明！", "抓到了");

}

private void Form1_MouseMove(object sender, MouseEventArgs e);

{

int border = 50;

int x = e.X;

int y = e.Y;

int left = btnCatchMe.Left;

int right = btnCatchMe.Right;

int top = btnCatchMe.Top;

int bottom = btnCatchMe.Bottom;

if (x > left - border && x < right + border && y > top - border && y

{

btnCatchMe.Top += (y > top ? -20 : 20);

if (btnCatchMe.Top > Form1.ActiveForm.Size.Height || btnCatchMe.Bottom < 0)

{

btnCatchMe.Top = Form1.ActiveForm.Size.Height / 2;

}

btnCatchMe.Left += (x > left ? -20 : 20);

if (btnCatchMe.Left > Form1.ActiveForm.Size.Width || btnCatchMe.Right < 0)

{

btnCatchMe.Left = Form1.ActiveForm.Size.Width / 2;

}

}

}
