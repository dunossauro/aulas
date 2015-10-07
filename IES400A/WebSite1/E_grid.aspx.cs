using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;

//Declarar notação absoluta da conexão, no lugar de Server.Map..., para eliminar notações repetitivas.
//string conexao = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + "<caminho>/Dados/Cadastro.accdb" + ";Persist Security Info=false";


public partial class E_grid : System.Web.UI.Page

{

    protected void Page_Load(object sender, EventArgs e)
    {
        LoadGrid();
    }

    protected void LoadGrid(){

        string conexao = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + Server.MapPath("~/Dados/Cadastro.accdb") + ";Persist Security Info=false";

        AppDatabase.OleDBTransaction ole = new AppDatabase.OleDBTransaction();
        ole.ConnectionString = conexao;

        DataTable TB = (DataTable)ole.Query("Select * FROM Clientes ;");

        GridView1.DataSource = TB;

        GridView1.DataBind();

    }
    
    protected void grid(object sender, EventArgs e)
    {
        AppDatabase.OleDBTransaction ole = new AppDatabase.OleDBTransaction();
        ole.ConnectionString = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + Server.MapPath("~/Dados/Cadastro.accdb") + ";Persist Security Info=false";

        DataTable TB = (DataTable)ole.Query("Select * FROM Clientes WHERE CODIGO=" + GridView1.SelectedRow.Cells[1].Text + ";");

        if (TB.Rows.Count == 1)
        {
            NomeCliente.Text = TB.Rows[0]["Nome"].ToString();
            EmailCliente.Text = TB.Rows[0]["Email"].ToString();
            TelefoneCliente.Text = TB.Rows[0]["Telefone"].ToString();
        }

    }
    
    protected void Salvar_Click(object sender, EventArgs e)
    {
        AppDatabase.OleDBTransaction ole = new AppDatabase.OleDBTransaction();
        ole.ConnectionString = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + Server.MapPath("~/Dados/Cadastro.accdb") + ";Persist Security Info=false";
        ole.Query("UPDATE Clientes SET nome='" + NomeCliente.Text + "', Email='" + EmailCliente.Text + "', Telefone='" + TelefoneCliente.Text + "' WHERE CODIGO=" + GridView1.SelectedRow.Cells[1].Text);

        LoadGrid();
    }
    
    protected void Excluir_Click(object sender, EventArgs e)
    {

        AppDatabase.OleDBTransaction ole = new AppDatabase.OleDBTransaction();
        ole.ConnectionString = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + Server.MapPath("~/Dados/Cadastro.accdb") + ";Persist Security Info=false";

        if (NomeCliente.Text.Trim() != "" && EmailCliente.Text.Trim() != "")
        {
            ole.Query("Delete FROM Clientes WHERE CODIGO=" + GridView1.SelectedRow.Cells[1].Text + ";");
        }
        NomeCliente.Text = "";
        EmailCliente.Text = "";
        TelefoneCliente.Text = "";

        LoadGrid();

    }

    protected void Busca_nome_TextChanged(object sender, EventArgs e)
    {
        buscar();
    }

    protected void buscar() {
        string conexao = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + Server.MapPath("~/Dados/Cadastro.accdb") + ";Persist Security Info=false";

        AppDatabase.OleDBTransaction ole = new AppDatabase.OleDBTransaction();
        ole.ConnectionString = conexao;

        DataTable TB = (DataTable)ole.Query("SELECT * FROM Clientes WHERE nome LIKE '%" + Busca_nome.Text + "%' ;");

        GridView1.DataSource = TB;

        GridView1.DataBind();
    }
}
