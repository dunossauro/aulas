<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="E_grid.aspx.cs" Inherits="E_grid" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">


    <h1>Editar cadastro com grid</h1>

    
    <h4>Buscar</h4>
    <asp:TextBox ID="Busca_nome" runat="server" AutoPostBack="true" OnTextChanged="Busca_nome_TextChanged"></asp:TextBox>
    
    
    <asp:Panel runat="server" ScrollBars="Auto" Width="10%" Height="10%">
       
         <asp:GridView Width="30%" Height="5%" ID="GridView1" runat="server" AutoGenerateSelectButton="True" OnSelectedIndexChanged="grid" CssClass="grid" ></asp:GridView>
        
    </asp:Panel>
        <br />
         Nome
        <br />
        <asp:TextBox ID="NomeCliente" runat="server"></asp:TextBox><br />

        Email
        <br />
        <asp:TextBox ID="EmailCliente" runat="server" ></asp:TextBox><br />

        Telefone
        <br />
        <asp:TextBox ID="TelefoneCliente" runat="server" ></asp:TextBox><br />

        <br />
        <asp:Button ID="Salvar" runat="server" Text="Salvar " OnClick="Salvar_Click"/>
        <asp:Button ID="Excluir" runat="server" Text="Excluir" OnClick="Excluir_Click"/>



</asp:Content>

