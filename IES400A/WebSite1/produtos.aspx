<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="produtos.aspx.cs" Inherits="produtos" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    
    <h1>Adesivos</h1>

    <table>
        <tr>
            <td width=10%; rowspan="3";> <img src="Images/169956-background.png"; width="200"; height="200"; /></td>
            <td class="linha"> Tamanhos: P;M;G.</td>
        </tr>
        <tr>
            <td class="linha">Adesivos com fundo transparente</td>
        </tr>
        <tr>
            <td class="linha">lorem lorem lorem lorem</td>
        </tr>
        <tr>
            <td rowspan="3"> <img src="Images/gnu-type.png"; width="200"; height="200"; /></td>
            <td class="linha">Tamanhos: P;M;G.</td>
        </tr>
        <tr>
            <td class="linha">Adesivos com fundo transparente</td>
        </tr>
        <tr>
            <td class="linha">lorem lorem lorem</td>
        </tr>
    </table>
</asp:Content>

