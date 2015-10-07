<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Cadastro.aspx.cs" Inherits="Cadastro" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

    <h1>Cadastro de Contatos</h1>
            <br />
            Nome<br />
                <asp:TextBox ID="NomeCliente" runat="server"></asp:TextBox>
            <br />
            Endereço<br />
                <asp:TextBox ID="Endereco" runat="server"></asp:TextBox>
            <br />
            Email<br />
                 <asp:TextBox ID="EmailCliente" runat="server"></asp:TextBox>
            <br />
            Telefone<br />
                <asp:TextBox ID="TelefoneCliente" runat="server" TextMode="SingleLine"></asp:TextBox>
            <br />
                <asp:Button ID="Gravar" runat="server" onClick="Gravar_Click" Text="Gravar" />

</asp:Content>

