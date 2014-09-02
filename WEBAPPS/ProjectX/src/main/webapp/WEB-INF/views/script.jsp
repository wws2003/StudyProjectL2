<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
<style type="text/css">
.ct-div {
	padding-left: 5%;
}
</style>
</head>
<body>
	<h2>Simplest CI !</h2>
	<c:choose>
		<c:when test="${scriptFileAvailable}">
			Service available
			<div class="ct-div">
				Script content:
				<form action=<c:url value="/script/submit"></c:url> id="submitForm" method="POST">
					<textarea rows="5" cols="80" name="content" form="submitForm">
					 <c:out value="${scriptFileContent}"></c:out>	
					</textarea>
					<br>
					<input type="submit" value="Submit">
				</form>
			</div>
		</c:when>
		<c:otherwise>
			Service not available
		</c:otherwise>
	</c:choose>
</body>
</html>