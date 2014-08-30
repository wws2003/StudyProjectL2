<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head></head>
<body>
	<h2>Hello world</h2>
	<c:choose>
		<c:when test="${serviceAvailable}">
			Service available
			<div>
				<b>Building list</b>
				<table>
					<c:forEach items="${buildingList}" var="element">
						<tr>
							<td>${element.id}</td>
							<td>${element.status}</td>
							<td>${element.beginTimeStamp}</td>
							<td>${element.logFilePath}</td>
						</tr>
					</c:forEach>
				</table>
			</div>
			<div>
				<b>Waiting list</b>
				<table>
					<c:forEach items="${waitingList}" var="element">
						<tr>
							<td>${element.id}</td>
							<td>${element.status}</td>
							<td>${element.beginTimeStamp}</td>
							<td>${element.logFilePath}</td>
						</tr>
					</c:forEach>
				</table>
			</div>
			<div>
				<b>Built list</b>
				<table>
					<c:forEach items="${builtList}" var="element">
						<tr>
							<td>${element.id}</td>
							<td>${element.status}</td>
							<td>${element.beginTimeStamp}</td>
							<td>${element.endTimeStamp}</td>
							<td>${element.logFilePath}</td>
						</tr>
					</c:forEach>
				</table>
			</div>
		</c:when>
		<c:otherwise>
			Service not available
		</c:otherwise>
	</c:choose>
</body>
</html>
