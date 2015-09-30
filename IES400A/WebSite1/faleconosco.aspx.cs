using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

//classe para enviar e-mail
using AppNet;

public partial class faleconosco : System.Web.UI.Page{
    protected void Page_Load(object sender, EventArgs e){
      
    }
    protected void Enviar_Click(object sender, EventArgs e){

        if (Nome.Text.Trim() == "") { 

           Nome.Text = "Seu Nome deve existir";

        } else if(Email.Text == ""){

            Email.Text = "Seu email deve ser digitado";

        } else{

            string body_email = Nome.Text + "\r\n" + Email.Text + "\r\n" + Telefone.Text + "\r\n" + Mensagem.Text + "\r \n \r \n  Fim da mensagem";
            
            //Propriedades do "enviar e-mail"
            AppNet.Mail enviar_email = new AppNet.Mail();
            enviar_email.Host = "Server";
            enviar_email.User = "User";
            enviar_email.Pass = "senha";
            enviar_email.Port = 587;


            if (enviar_email.Send("TO","FROM","Assunto","Corpo")){

                Mensagem.Text = "ENVIADO";

            } else{

                Mensagem.Text = "Erro, envie novamente";
            }


        }
    }
}
