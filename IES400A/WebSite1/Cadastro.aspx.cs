using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Cadastro : System.Web.UI.Page {
    protected void Page_Load(object sender, EventArgs e) {

    }
    protected void Gravar_Click(object sender, EventArgs e) {
        
        //string de conexao com o banco de dados "Access provedor  Microsoft.ACE.OLEDB.12.0"
        string conexao = @"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" +
            Server.MapPath("~/Dados/Cadastro.accdb") + ";Persist Security Info=false";

        //Query SQL para inserir um registro
        string comando = "INSERT INTO Clientes(Nome,Email,Telefone) VALUES('" +
            NomeCliente.Text + "','" + EmailCliente.Text + "','" + TelefoneCliente.Text + "');";

        AppDatabase.OleDBTransaction ole = new AppDatabase.OleDBTransaction();
        ole.ConnectionString = conexao;
        ole.Query(comando);
    }
}
