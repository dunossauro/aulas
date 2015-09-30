<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="faleconosco.aspx.cs" Inherits="faleconosco" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
       <div class="centro">

        <img src="Images/email1.jpg" />

        <br />
        Nome:<br />
        <asp:textbox id="Nome" runat="server"></asp:textbox>
        <br />
        E-mail:<br />
        <asp:textbox id="Email" runat="server"></asp:textbox>
        <br />
        Telefone:<br />
        <asp:textbox id="Telefone" runat="server"></asp:textbox>
        <br />
        Mensagem:<br />
        <asp:textbox id="Mensagem" runat="server" rows="6"></asp:textbox>

        <br />
        <br />

        <asp:button id="Enviar" onclick="Enviar_Click" runat="server" text="Enviar" />

    </div>
</asp:Content>

