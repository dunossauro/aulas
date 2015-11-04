<%@ Page Language="C#" %>
<!DOCTYPE html>
<html>

<head runat="server">
	<title>Support</title>
</head>

<body>
	<h2>Bem vindo a pagina do suporte</h2>

	<form action="__acao__" method="post" target="_blank">

		<p><label>Usuario: <input type="text" name="user"></label></p>
		<p><label>Senha: <input type="password" name="pass"></label></p>
		<p><label>lembrar Senha <input type="radio"></label></p>
		<p><input type="submit" value="Logar!"></p>

	</form>

</body>
</html>
