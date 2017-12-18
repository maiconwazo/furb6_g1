using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Entity;
using System.Data.Entity.Migrations;
using Servidor.Models;
using System.Data.Entity.ModelConfiguration.Conventions;

namespace Servidor.DAO
{
	public class DefaultContext<T> : DbContext where T: Record
	{
		public DbSet<T> DataSet { get; set; }
		public DefaultContext() : base("DefaultContextConnectionString")
		{
		}

		protected override void OnModelCreating(DbModelBuilder modelBuilder)
		{
			modelBuilder.Conventions.Remove<OneToManyCascadeDeleteConvention>();
			Database.SetInitializer(new DropCreateDatabaseAlways<DefaultContext<T>>());
		}
	}
}
